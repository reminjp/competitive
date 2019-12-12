#ifndef STATE_HPP
#define STATE_HPP

#include <cstdio>
#include <cassert>
#include <string>
#include <tuple>
#include <utility>
#include <iterator>
#include <functional>

enum car_status {
  NORMAL = 0,
  WARNING = 1,
  BROKEN = 2,
};

enum edge_bittype {
  LOCALWAY = 0,
  SPEEDWAY_1 = 1,
  SPEEDWAY_2 = 2,
  SPEEDWAY_3 = 3,
  SPEEDWAY_4 = 4,
  INTO_SPEEDWAY = 5,
  GOOUT_SPEEDWAY = 6,
};

class state : public agent {
public:
  using time_type = int_fast64_t;
  using query_type = int;
  using order_num_type = order::order_num_type;
  using score_type = int_fast64_t;

  static const double MOVE_PROBABILITY;
  static const std::string OK_STR;
  static const std::string NG_STR;
  static const std::string JAM_STR;
  static const std::string WAIT_STR;
  const size_t depot_index;

  graph<edge> G;
  std::vector<size_t> freq_pool;
  std::vector< std::pair<double, double> > prob_segment;

  // 渋滞
  std::vector< std::vector<bool> > jam;
  
  // 信号
  time_type p_light;
  
  // 車の故障
  car_status status;
  time_type duration_until_broken, warning_time, broken_time, repair_end_time;

  // 信号および故障による待ち時間
  time_type waiting_time;
  
  // 発生した注文をすべて記録 (id を 1-indexed にするために、先頭にダミー注文を入れる)
  std::vector<order> order_list;
  // グラフの、depot 以外の頂点それぞれについて未処理の注文を記録
  std::vector< std::set<order_num_type> > pending_order_list;
  // depot の頂点について、商品が agent に受け渡されていない注文を記録
  // agent について、その時点で保有している商品に対応する注文を記録
  std::set<order_num_type> depot_order_list, agent_order_list;
  // キャンセル予定の注文を記録
  std::vector< std::vector<order_num_type> > to_be_canceled_order_list;
  time_type current_time, max_time;
  random_number rnd;
  FILE *in, *out;
  
  state(const graph<edge> &G_, const time_type &max_time_,
	const time_type &p_light_, const time_type &duration_until_waining_,
	const std::vector< std::vector<bool> >& jam_,
	const std::vector< std::pair<double, double> > &prob_segment,
	uint_fast64_t seed, size_t v,
	FILE *in_, FILE *out_);

  // speedway の上かどうか
  int edge_bit(size_t u, size_t v) const;
  bool is_speedway_edge(size_t u, size_t v) const;
  bool is_edgebit(size_t u, size_t v, size_t k) const;
  time_type calc_traffic_light() const;
  bool occur_traffic_jam(size_t k, time_type t) const;
  double calc_move_probability(size_t x, size_t y) const;
  
  double order_prob_by_time();
  order_num_type next_dst();

  // コンテスタントから命令を受け取る
  query_type input_by_agent();

  // コンテスタントに、受け取った命令が妥当なものであるかを伝える
  void output_verdict(std::string s);

  // 新たな注文の一覧を出力
  void output_new_orders(std::vector<order> new_orders_list);

  // 注文をランダムに追加する
  // (追加されたものは注文リストに追加し、コンテスタントに向けて出力)
  void get_order();
  time_type calculate_cancel_extra_time();
  
  // 現在地に応じて情報を更新
  // - agent が持つ商品が増える (depot にある商品が減る)
  // - agent が注文を処理し終える (各頂点にある未処理の注文が減り、終了時刻が記録される)
  void get_removed_order_list();
  void get_completed_order_list();
  
  // ステップ数を 1 進める
  // (コンテスタントから命令を受け取る・進める・状態更新・時間情報更新)
  // 不正な入力を受け取った時など、正常に終了しない時に false を返す
  bool increment_step();
  
  // 環境の更新 (問題 C での渋滞等の変化を想定)
  void manage_broken_info();         // 車の故障
  time_type calculate_car_ok_time();
  
  void output_jam_info();            // 渋滞の状況
  void manage_canceled_order_info(); // 注文のキャンセル
  void update_environment();

  // スコア計算
  score_type calculate_score();

  // 注文の数の合計
  size_t get_num_of_orders() const;
  // 0-indexed で k 番目の注文情報を得る
  order get_kth_order(size_t k) const;
};

const double state::MOVE_PROBABILITY = 0.1;
const std::string state::OK_STR = "OK";
const std::string state::NG_STR = "NG";
const std::string state::JAM_STR = "JAM";
const std::string state::WAIT_STR = "WAIT";

state::state(const graph<edge> &G_, const time_type &max_time_,
	     const time_type &p_light_, const time_type &duration_until_broken_,
	     const std::vector< std::vector<bool> > &jam_,
	     const std::vector< std::pair<double, double> > &prob_segment_,
	     uint_fast64_t seed, size_t v=0,
	     FILE *in_=stdin, FILE *out_=stdout)
  : agent(v), depot_index(v), G(G_), freq_pool(),
    prob_segment(prob_segment_),
    jam(jam_), p_light(p_light_),
    status(NORMAL), duration_until_broken(duration_until_broken_),
    warning_time(-1), broken_time(-1), repair_end_time(-1),
    waiting_time(0),
    order_list(), pending_order_list(G_.size()),
    depot_order_list(), agent_order_list(),
    to_be_canceled_order_list(max_time_ + 1),
    current_time(0), max_time(max_time_), rnd(seed), in(in_), out(out_) {
  order_list.emplace_back(0, -1, -1); // ダミー注文
  G.sort_edges();

  for(size_t i=0; i<G.size(); i++) {
    for(int j=0; j<static_cast<int>(G.f[i]); j++) {
      freq_pool.emplace_back(i);
    }
  }
}

int state::edge_bit(size_t u, size_t v) const{
  assert(u != static_cast<size_t>(-1));
  assert(v != static_cast<size_t>(-1));
  
  size_t idx = G.find(u, v);
  assert(idx != static_cast<size_t>(-1));
  return G[u][idx].bit;  
}

bool state::is_speedway_edge(size_t u, size_t v) const {
  const int mask = 0x1e;
  return (edge_bit(u, v) & mask) > 0;
}

bool state::is_edgebit(size_t u, size_t v, size_t k) const {
  return edge_bit(u, v) >> k & 1;
}

state::time_type state::calc_traffic_light() const {
  time_type s = current_time / p_light;
  time_type m = current_time % p_light;
  return (s % 2 == 0) ? 0 : p_light - m;
}

bool state::occur_traffic_jam(size_t k, time_type t) const {
  return jam[k][t];
}

double state::calc_move_probability(size_t x, size_t y) const {
  assert(x != static_cast<size_t>(-1));
  assert(y != static_cast<size_t>(-1));
  size_t edge_idx = G.find(x, y);
  int bit = G[x][edge_idx].bit;

  for(size_t i=1; i<=4; i++) {
    // 該当する道が speedway 1..4 のいずれかに属していて、
    // 渋滞が発生していた場合、移動確率が変化
    if((bit >> i & 1) and occur_traffic_jam(i-1, current_time)) {
      return MOVE_PROBABILITY;
    }
  }
  // 普通は常に動ける
  return 1.0;
}

// 注文確率の計算
double state::order_prob_by_time() {
  double t = 1.0 * current_time / max_time;

  assert(prob_segment.size() > 0);
  if(prob_segment.size() == 1) {
    return prob_segment.front().second;
  }
  else {
    for(size_t i=0; i+1<prob_segment.size(); i++) {
      double t1 = prob_segment[i].first, t2 = prob_segment[i+1].first;
      double p1 = prob_segment[i].second, p2 = prob_segment[i+1].second;
      if(t1 <= t and t < t2) {
	double delta_p = p2 - p1;
	double ratio = (t - t1) / (t2 - t1);
	return p1 + ratio * delta_p;
      }
    }
    assert(false);
    return -1;
  }
}

state::order_num_type state::next_dst() {
  assert(freq_pool.size() > 0);
  return freq_pool[ rnd.next_uint(0, freq_pool.size() - 1) ];
}

state::query_type state::input_by_agent() {
  int query;
  fscanf(in, "%d", &query);
  return query;
}

void state::output_verdict(std::string s) {
  fprintf(out, "%s", s.c_str());
  if(s == WAIT_STR) {
    assert(waiting_time > 0);
    fprintf(out, " %" PRId64 "\n", waiting_time);
  }
  else {
    fprintf(out, "\n");
  }
  fflush(out);
}

void state::output_new_orders(std::vector<order> new_orders_list) {
  fprintf(out, "%zu\n", new_orders_list.size());
  using o_nt = order_num_type;
  for(const auto &e : new_orders_list) {
    o_nt id, dst, start_time;
    std::tie(id, dst, start_time, std::ignore) = e.get_order_info();
    fprintf(out, "%" PRId64 " %" PRId64 "\n", id, dst + INDEXED);
  }
  fflush(out);
}

void state::get_order() {
  using o_nt = order_num_type;

  std::vector<order> new_orders_list;
  if(rnd.next_double() <= order_prob_by_time()) {
    o_nt id = order_list.size();
    o_nt dst = next_dst();
    o_nt start_time = current_time;
    o_nt canceled_time = current_time + calculate_cancel_extra_time();
    canceled_time = std::min(max_time, canceled_time);
    
    // 全体のリストに追加
    order_list.emplace_back(id, dst, start_time, -1, canceled_time);

    // dst 番目の頂点に「待ち状態の注文」として情報を追加
    pending_order_list[dst].emplace(id);

    // depot に「持ち出し待ちの注文」として情報を追加
    depot_order_list.emplace(id);

    // キャンセル予定リストに追加
    to_be_canceled_order_list[canceled_time].emplace_back(id);

    new_orders_list.emplace_back(id, dst, start_time, -1, canceled_time);
  }
  output_new_orders(new_orders_list);
}

state::time_type state::calculate_cancel_extra_time() {
  double x = rnd.next_double_by_power_law(0.5, 1.0 / max_time);
  x += 0.01 / max_time;
  return static_cast<time_type>(2000 + 1.0 / x);
}

void state::get_removed_order_list() {
  using o_nt = order_num_type;
  size_t agent_v = ep_1;

  // depot から回収された商品に対応する注文一覧
  std::vector<o_nt> removed_order_list;
  if(agent_state == ON_VERTEX and agent_v == depot_index) {
    removed_order_list.reserve(depot_order_list.size());
    for(const auto &e : depot_order_list) {
      removed_order_list.emplace_back(e);
      agent_order_list.emplace(e);
    }
    depot_order_list.clear();
  }

  fprintf(out, "%zu\n", removed_order_list.size());
  for(const auto &e : removed_order_list) {
    fprintf(out, "%" PRId64 "\n", e);
  }

  fflush(out);
}

void state::get_completed_order_list() {
  using o_nt = order_num_type;
  size_t agent_v = ep_1;

  // 処理された注文一覧
  std::vector<o_nt> completed_order_list;
  if(agent_state == ON_VERTEX and agent_v != depot_index) {
    set_intersection(pending_order_list[agent_v].begin(),
		     pending_order_list[agent_v].end(),
		     agent_order_list.begin(),
		     agent_order_list.end(),
		     std::back_inserter(completed_order_list));
    for(const auto &e : completed_order_list) {
      pending_order_list[agent_v].erase(e);
      agent_order_list.erase(e);
      // 終了時間を記録
      order_list[e].register_end_time(current_time);
    }
  }

  fprintf(out, "%zu\n", completed_order_list.size());
  for(const auto &e : completed_order_list) {
    fprintf(out, "%" PRId64 "\n", e);
  }
  
  fflush(out);
}

bool state::increment_step() {
  const int V = static_cast<int>(G.size());

  // 環境の変化
  update_environment();
  
  // 新しく注文が来る
  // (注文リストを更新してコンテスタントに情報を送らないといけない)
  get_order();
  get_removed_order_list();
  
  // コンテスタントからの命令を受け取る
  query_type query = input_by_agent();

  // [信号と渋滞は同時発生しない]
  // 信号: speedway の外から speedway の中に入る時のみ発生
  // 　　　待たなければならない場合は OK の代わりに WAIT [待ち時間] を出す
  // 渋滞: 同じ speedway 間の移動の時のみ発生
  //       動けない場合は OK の代わりに JAM を出して通知
  
  // 命令を処理 (agent を動かすだけ！)
  if(query == -1) {
    // stay
    waiting_time = std::max<time_type>(0, waiting_time - 1);
    output_verdict(waiting_time > 0 ? WAIT_STR : OK_STR);

    // 命令を処理し終わったので 1 分経過させる
    current_time++;
  }
  else {
    int vertex = query - static_cast<int>(INDEXED);
    // 車が故障しているときに移動しようとした場合
    // 待たなければならないのに移動しようとした場合
    if(status == BROKEN or waiting_time > 0) {
      output_verdict(NG_STR);
      return false;
    }
    // 上記以外で移動しようとした場合 (待ち時間は必ず 0)
    else if(0 <= vertex and vertex < V) {
      if(is_valid_move(G, vertex)) {
	// x -> y の移動確率の計算 (JAM のときのみ 1 でない)
	int x = ep_1, y = ep_2;
	// x に向かって移動している場合 (入れ替え: 行き先 y に x を入れる)
	if(x == vertex) std::swap(x, y);
	// 頂点上にいた場合 (行き先 y に代入)
	if(agent_state == ON_VERTEX) y = vertex;
	double prob = calc_move_probability(x, y);
	
	// move, 待ち時間再計算
	bool can_move = proceed(G, vertex, rnd, prob);

	// 命令を処理し終わったので 1 分経過させる
	current_time++;
	
	// ちゃんと移動ができた
	// x が speedway 外、y が speedway 内
	// 移動後に agent が ON_VERTEX である -> 信号の影響あり
	if(can_move and is_edgebit(x, y, INTO_SPEEDWAY) and agent_state == ON_VERTEX) {
	  waiting_time = calc_traffic_light();
	}

	// 移動できてないなら JAM
	if(!can_move) {
	  output_verdict(JAM_STR);
	}
	// 待ち時間があるなら WAIT
	else if(waiting_time > 0) {
	  output_verdict(WAIT_STR);
	}
	// 移動できて待ち時間もないなら OK
	else {
	  output_verdict(OK_STR);
	}
      }
      else {
	output_verdict(NG_STR);
	return false;
      }
    }
    // invalid input
    else {
      output_verdict(NG_STR);
      return false;
    }
  }

  // その時点で捌いた注文のリスト・新しく持った商品のリストなどを得る
  get_completed_order_list();

  assert(pending_order_list[depot_index].empty());

  return true;
}

void state::manage_broken_info() {
  // 修理完了 (修理時間を待つか、壊れる前に depot に到達)
  if(current_time == repair_end_time or (ep_1 == depot_index and current_time <= broken_time)) {
    status = NORMAL;
    warning_time = broken_time = repair_end_time = -1;
  }
  // 次の故障時間の設定 (何も設定されていない場合)
  if(warning_time < 0) {
    assert(status == NORMAL);
    warning_time = current_time + calculate_car_ok_time();
    broken_time = warning_time + duration_until_broken;
    repair_end_time = broken_time + 300;
  }
  // 故障するかも
  if(current_time == warning_time) {
    assert(status == NORMAL);
    status = WARNING;
  }
  // 故障したかどうか
  if(current_time == broken_time) {
    assert(status == WARNING);
    status = BROKEN;
  }

  // 出力
  switch(status) {
  case NORMAL:
    fprintf(out, "NOT_BROKEN\n");
    break;
  case WARNING:
    fprintf(out, "WARNING %" PRId64 "\n", broken_time - current_time);
    break;
  case BROKEN:
    fprintf(out, "BROKEN\n");
    break;
  }
  fflush(out);
}

state::time_type state::calculate_car_ok_time() {
  double x = rnd.next_double_by_power_law(2.5, 1.0 / max_time);
  x += 0.01 / max_time;
  return static_cast<time_type>(1.0 / x);
}

void state::output_jam_info() {
  for(size_t i=0; i<4; i++) {
    fprintf(out, "%d%c", jam[i][current_time] ? 1 : 0, " \n"[i + 1 == 4]);
  }
  fflush(out);
}

void state::manage_canceled_order_info() {
  std::vector<order_num_type> canceled_order_list;
  for(auto id : to_be_canceled_order_list[current_time]) {
    if(!order_list[id].complete_order()) {
      order_list[id].set_canceled(current_time);
      depot_order_list.erase(id);
      agent_order_list.erase(id);

      size_t dst = std::get<1>(order_list[id].get_order_info());
      assert(pending_order_list[dst].count(id));
      pending_order_list[dst].erase(id);
      
      canceled_order_list.emplace_back(id);
    }
  }

  fprintf(out, "%zu\n", canceled_order_list.size());
  // キャンセルされた注文一覧を出力
  for(auto id : canceled_order_list) {
    fprintf(out, "%" PRId64 "\n", id);
  }
  fflush(out);
}

void state::update_environment() {
  // 車の故障について
  manage_broken_info();

  // 渋滞状況について
  output_jam_info();

  // 注文のキャンセルについて
  manage_canceled_order_info();
}

state::score_type state::calculate_score() {
  size_t num_of_orders = get_num_of_orders();

  auto func = [&](score_type s) {
    return s * s;
  };

  score_type score = 0;
  for(size_t i=0; i<num_of_orders; i++) {
    // キャンセルされた注文は無視
    if(get_kth_order(i).is_canceled()) continue;

    time_type start_time, end_time;
    std::tie(std::ignore, std::ignore, start_time, end_time) = get_kth_order(i).get_order_info();
    if(end_time != -1) {
      score += func(max_time) - func(end_time - start_time);
    }
  }
  return score;
}

size_t state::get_num_of_orders() const {
  return order_list.size() - 1;
}

order state::get_kth_order(size_t k) const {
  return order_list[k + 1];
}

#endif
