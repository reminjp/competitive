#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

constexpr int W = 20, H = 20;
constexpr int NODE_COUNT = H * W;
constexpr int EDGE_COUNT = (2 * W - 1) * H - W;

const string TOKEN = "210401b86da937e931cd3c0c52a630a806d3e02a3813e9cd34cba59a89335298";
const string API_URL = "https://obt.tenka1.klab.jp/api";
constexpr int CLAIM_TIME_LIMIT = 500;

class Timer {
 public:
  Timer() : time_begin(Now()) {}
  int Elapsed() { return std::chrono::duration_cast<std::chrono::milliseconds>(Now() - time_begin).count(); }

 private:
  std::chrono::system_clock::time_point time_begin;
  static std::chrono::system_clock::time_point Now() { return std::chrono::system_clock::now(); }
};

string Get(string url) {
  cerr << "GET " << url << endl;
  FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
  if (f == NULL) perror("error");
  char buffer[1024];
  string response;
  while (!feof(f)) {
    if (fgets(buffer, 1024, f) == NULL) break;
    response += (string)(buffer);
  }
  pclose(f);
  cerr << response << endl;
  return response;
}

struct Game {
  int id, t;
};

struct Graph {
  int n, m;
  vector<int> s, t, c;
  Graph() {}
  Graph(int n, int m) : n(n), m(m), s(n), t(m), c(EDGE_COUNT) {}
};

Game get_game() {
  stringstream ss;
  ss << Get(API_URL + "/game");
  Game game;
  ss >> game.id >> game.t;
  return game;
}

Graph get_graph(int game_id) {
  stringstream ss;
  ss << Get(API_URL + "/stage/" + to_string(game_id));
  int n, m;
  ss >> n >> m;
  Graph graph(n, m);
  for (auto &e : graph.s) ss >> e;
  for (auto &e : graph.t) ss >> e;
  for (auto &e : graph.c) ss >> e;
  return graph;
}

string get_claim_edge(int game_id, int edge_index) {
  stringstream ss;
  ss << Get(API_URL + "/claim/" + TOKEN + "/" + to_string(game_id) + "/" + to_string(edge_index));
  string status;
  ss >> status;
  return status;
}

struct Point {
  int y, x;
};

Point node_index_to_position(int node_index) { return Point{node_index / W, node_index % W}; }

int edge_position_to_index(int y, int x, int direction) {
  switch (direction) {
    case 0:  // U
      return (2 * W - 1) * (y - 1) + (W - 1) + x;
    case 1:  // D
      return (2 * W - 1) * y + (W - 1) + x;
    case 2:  // L
      return (2 * W - 1) * y + (x - 1);
    case 3:  // R
      return (2 * W - 1) * y + x;
  }
  return -1;  // exception
}

int main() {
  Game game;
  Graph graph;
  vector<int> edges_to_claim;

  while (true) {
    auto prev_game = game;
    game = get_game();
    if (game.id == -1) return 0;

    Timer timer;

    if (prev_game.id == 0 || prev_game.id != game.id) {
      cerr << "game " << game.id << endl;

      set<int> edges_to_claim_set;
      graph = get_graph(game.id);

      vector<vector<bool>> is_connected(NODE_COUNT, vector<bool>(NODE_COUNT));
      vector<int> connected_count(NODE_COUNT);
      int connected_limit_s = (graph.m - 1) / graph.n + 1;
      int connected_limit_t = (graph.n - 1) / graph.m + 1;
      for (int c = (game.t - 1000) / (CLAIM_TIME_LIMIT + 100); edges_to_claim_set.size() < c;) {
        int min_cost = H + W, min_s = 0, min_t = 0;
        for (auto s : graph.s) {
          if (connected_count[s] >= connected_limit_s) continue;
          for (auto t : graph.t) {
            if (connected_count[t] >= connected_limit_t) continue;
            if (is_connected[s][t]) continue;
            auto ps = node_index_to_position(s), pt = node_index_to_position(t);
            int cost = abs(pt.y - ps.y) + abs(pt.x - ps.x);
            if (cost < min_cost) {
              min_cost = cost;
              min_s = s;
              min_t = t;
            }
          }
        }

        if (edges_to_claim_set.size() + min_cost > c) break;

        is_connected[min_s][min_t] = true;
        connected_count[min_s]++;
        connected_count[min_t]++;
        {
          auto ps = node_index_to_position(min_s), pt = node_index_to_position(min_t);
          while (ps.y != pt.y || ps.x != pt.x) {
            if (abs(pt.y - ps.y) >= abs(pt.x - ps.x)) {
              if (ps.y > pt.y) {
                edges_to_claim_set.insert(edge_position_to_index(ps.y, ps.x, 0));
                ps.y--;
              } else {
                edges_to_claim_set.insert(edge_position_to_index(ps.y, ps.x, 1));
                ps.y++;
              }
            } else {
              if (ps.x > pt.x) {
                edges_to_claim_set.insert(edge_position_to_index(ps.y, ps.x, 2));
                ps.x--;
              } else {
                edges_to_claim_set.insert(edge_position_to_index(ps.y, ps.x, 3));
                ps.x++;
              }
            }
          }
        }
      }

      edges_to_claim = vector<int>(edges_to_claim_set.begin(), edges_to_claim_set.end());
    }

    if (!edges_to_claim.empty()) {
      auto status = get_claim_edge(game.id, edges_to_claim.back());
      cerr << "edge " << edges_to_claim.back() << " " << status << endl;
      if (status == "ok" || status == "already_claimed") edges_to_claim.pop_back();
      cerr << "remaining edges " << edges_to_claim.size() << endl;
    }

    usleep(1000 * min(game.t, CLAIM_TIME_LIMIT - timer.Elapsed()));
  }
}
