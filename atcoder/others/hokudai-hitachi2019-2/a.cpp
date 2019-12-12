#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
constexpr int STORE = 0;

// union_find.cpp {
class UnionFind {
 private:
  std::vector<size_t> parent;
  std::vector<size_t> rank;
  std::vector<size_t> sizes;

 public:
  UnionFind(size_t n) : parent(n), rank(n), sizes(n, 1) {
    for (size_t i = 0; i < n; i++) parent[i] = i;
  }
  void Unite(size_t a, size_t b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      parent[a] = b;
    } else {
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
    sizes[Find(a)] = sizes[a] + sizes[b];
  }
  int Find(size_t a) { return parent[a] == a ? a : parent[a] = Find(parent[a]); }
  int Size(size_t a) { return sizes[Find(a)]; }
};
// }

inline int RandTerm(int term) { return rand() % term; }

inline int RandMinTerm(int min, int term) { return min + rand() % (term - min); }

double ExponentialUpperProbability(double mu, double x) { return exp(-x / mu); }

double PowerUpperProbability(double epsilon, double median, double x) {
  double mu = median / (pow(2.0, 1.0 / epsilon) - 1.0);
  return pow(1 + x / mu, -epsilon);
}

struct Graph {
  int n;
  vector<vector<int>> edges_by_node;
  vector<vector<int>> adjacency_matrix, type_matrix, distance_matrix, next_node_matrix;

  Graph(int n)
      : n(n),
        edges_by_node(n),
        adjacency_matrix(n, vector<int>(n, INF)),
        type_matrix(n, vector<int>(n)),
        distance_matrix(n, vector<int>(n, INF)),
        next_node_matrix(n, vector<int>(n)) {
    for (int i = 0; i < n; i++) distance_matrix[i][i] = 0;
    for (auto& e : next_node_matrix) iota(e.begin(), e.end(), 0);
  }

  void AddEdge(int from, int to, int cost, int type1, int type2) {
    edges_by_node[from].push_back(to);
    edges_by_node[to].push_back(from);
    adjacency_matrix[from][to] = adjacency_matrix[to][from] = cost;
    distance_matrix[from][to] = distance_matrix[to][from] = cost;
    type_matrix[from][to] = type1;
    type_matrix[to][from] = type2;
  }

  void Setup() {
    // Warshall-Floyd algorithm
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (distance_matrix[i][k] + distance_matrix[k][j] < distance_matrix[i][j]) {
            distance_matrix[i][j] = distance_matrix[i][k] + distance_matrix[k][j];
            next_node_matrix[i][j] = next_node_matrix[i][k];
          }
        }
      }
    }
  }

  inline int Distance(int node1, int node2) const { return distance_matrix[node1][node2]; }
};

struct Order {
  int dst, time;
};

struct OrderContainer {
  vector<Order> v;
  set<int> created_id_set, put_id_set, achieved_id_set, canceled_id_set;
  vector<set<int>> created_order_id_set_by_dst, put_order_id_set_by_dst;

  OrderContainer(int t, int n) : v(t), created_order_id_set_by_dst(n), put_order_id_set_by_dst(n) {}

  bool Create(int id, int dst, int time) {
    v[id].dst = dst;
    v[id].time = time;
    created_id_set.insert(id);
    created_order_id_set_by_dst[v[id].dst].insert(id);
    return true;
  }

  bool Put(int id) {
    if (!created_id_set.count(id)) return false;
    created_id_set.erase(id);
    put_id_set.insert(id);
    created_order_id_set_by_dst[v[id].dst].erase(id);
    put_order_id_set_by_dst[v[id].dst].insert(id);
    return true;
  }

  bool Achieve(int id) {
    if (!put_id_set.count(id)) return false;
    put_id_set.erase(id);
    achieved_id_set.insert(id);
    put_order_id_set_by_dst[v[id].dst].erase(id);
    return true;
  }

  bool Cancel(int id) {
    if (created_id_set.count(id)) {
      created_id_set.erase(id);
      canceled_id_set.insert(id);
      created_order_id_set_by_dst[v[id].dst].erase(id);
      return true;
    }
    if (put_id_set.count(id)) {
      put_id_set.erase(id);
      canceled_id_set.insert(id);
      put_order_id_set_by_dst[v[id].dst].erase(id);
      return true;
    }
    return false;
  }
};

struct Car {
  int node = STORE;
  int distance = 0;
  bool is_broken = false;
  int time_to_light = 0;
};

void SolveTravelingSalesmanProblem(const Graph& graph, vector<int>& route, const int iteration_count) {
  int min_cost = 0;
  for (int i = 0; i < route.size(); i++) min_cost += graph.Distance(route[i], route[(i + 1) % route.size()]);

  for (int i = 0; i < iteration_count; i++) {
    int l = RandMinTerm(1, route.size());
    int r = RandMinTerm(l + 1, route.size() + 1);

    int next_cost = min_cost;

    next_cost -= graph.Distance(route[l - 1], route[l]);
    next_cost += graph.Distance(route[l - 1], route[r - 1]);

    next_cost -= graph.Distance(route[r - 1], route[r % route.size()]);
    next_cost += graph.Distance(route[l], route[r % route.size()]);

    if (next_cost < min_cost) {
      min_cost = next_cost;
      reverse(route.begin() + l, route.begin() + r);
    }
  }
}

int main() {
  srand(0);

  // input (test case)
  int node_count, edge_count;
  cin >> node_count >> edge_count;

  Graph graph(node_count);
  for (int i = 0; i < edge_count; i++) {
    int from, to, cost, type1, type2;
    cin >> from >> to >> cost >> type1 >> type2;
    graph.AddEdge(from - 1, to - 1, cost, type1, type2);
  }

  vector<int> frequency(node_count);
  for (auto& e : frequency) cin >> e;

  vector<vector<int>> jam_start_time(4, vector<int>(4));
  for (auto& v : jam_start_time) {
    for (auto& e : v) cin >> e;
  }

  int light_cycle, warning_time, end_time;
  cin >> light_cycle >> warning_time >> end_time;

  // preprocess
  vector<Graph> graph_with_jam;
  graph_with_jam.reserve(1 << 4);
  for (int b = 0; b < (1 << 4); b++) {
    graph_with_jam.push_back(graph);
    auto& g = graph_with_jam[b];
    g = graph;

    for (int i = 0; i < node_count; i++) {
      for (int j = 0; j < node_count; j++) {
        if (1 <= g.type_matrix[i][j] && g.type_matrix[i][j] <= 4) {
          if ((b >> g.type_matrix[i][j] - 1) & 1) g.adjacency_matrix[i][j] *= 10;
        } else if (g.type_matrix[i][j] == 5) {
          g.adjacency_matrix[i][j] += light_cycle;
        }
      }
    }

    g.Setup();
  }

  graph.Setup();

  vector<int> group_of_nodes(node_count, -1);
  {
    UnionFind uf(node_count);
    for (int i = 0; i < node_count; i++) {
      for (auto j : graph.edges_by_node[i]) {
        if (graph.type_matrix[i][j] == 0) uf.Unite(i, j);
      }
    }
    map<int, int> m;
    for (int i = 0; i < node_count; i++) {
      int f = uf.Find(i);
      if (uf.Size(i) > 1) {
        if (!m.count(f)) {
          int s = m.size();
          m[f] = s;
        }
        group_of_nodes[i] = m[f];
      }
    }
  }

  // iterate [0, end_time)
  OrderContainer orders(end_time, node_count);
  Car car;
  queue<int> route;

  for (int time = 0; time < end_time; time++) {
    // input (before the command)
    string car_status;
    int car_status_time = 0;
    cin >> car_status;
    if (car_status == "WARNING") cin >> car_status_time;
    car.is_broken = car_status == "BROKEN";

    int jam = 0;
    for (int i = 0; i < 4; i++) {
      int e;
      cin >> e;
      jam |= e << i;
    }

    int canceled_order_count;
    cin >> canceled_order_count;
    vector<int> cancel_order_ids(canceled_order_count);
    for (auto& id : cancel_order_ids) {
      cin >> id;
      id--;
      orders.Cancel(id);
    }

    int created_order_count;
    cin >> created_order_count;
    vector<int> created_order_ids(created_order_count);
    for (auto& id : created_order_ids) {
      int dst;
      cin >> id >> dst;
      id--;
      orders.Create(id, dst - 1, time);
    }

    int put_order_count;
    cin >> put_order_count;
    vector<int> put_order_ids(put_order_count);
    for (auto& id : put_order_ids) {
      cin >> id;
      id--;
      orders.Put(id);
    }

    // solve
    if (car.distance == 0 && !car.is_broken && car.time_to_light == 0) {
      // arriving at the node
      if (car_status == "WARNING" && graph_with_jam[jam].Distance(car.node, STORE) <= car_status_time) {
        while (!route.empty()) route.pop();
      } else if (car.node == STORE && put_order_count) {
        vector<vector<int>> routes(4);
        vector<double> scores(4);
        for (int k = 0; k < routes.size(); k++) {
          routes[k].reserve(node_count);
          routes[k].push_back(STORE);
          for (int i = 0; i < node_count; i++) {
            if (group_of_nodes[i] == k && !orders.put_order_id_set_by_dst[i].empty()) routes[k].push_back(i);
          }

          if (routes[k].size() < 2) continue;

          SolveTravelingSalesmanProblem(graph_with_jam[jam], routes[k], 5e6);
          routes[k].erase(routes[k].begin());

          int t = time, i = STORE;
          for (auto j : routes[k]) {
            t += graph_with_jam[jam].Distance(i, j);
            i = j;

            for (auto o : orders.put_order_id_set_by_dst[j]) {
              int wt = t - orders.v[o].time;
              // double r = wt <= 2000 ? 1.0 : 0.5;
              double r = 1.0;
              scores[k] += (end_time * end_time - wt * wt) * r;
            }
          }
          t += graph_with_jam[jam].Distance(i, STORE);

          if (t - time != 0) scores[k] /= t - time;
        }

        while (!route.empty()) route.pop();
        for (auto e : routes[max_element(scores.begin(), scores.end()) - scores.begin()]) route.push(e);
      }

      while (!route.empty() && route.front() != STORE && orders.put_order_id_set_by_dst[route.front()].empty())
        route.pop();

      // update the car.node
      int next_node = graph.next_node_matrix[car.node][route.empty() ? STORE : route.front()];
      car.distance = car.node == next_node ? 0 : graph.adjacency_matrix[car.node][next_node];
      car.node = next_node;
    }

    // output
    int command = -1;

    if (car.distance > 0 && car.time_to_light == 0 && !car.is_broken) {
      command = car.node + 1;
    }

    cout << command << endl;

    // input (after the command)
    string verdict;
    cin >> verdict;
    if (verdict == "NG") break;

    if (verdict == "WAIT") {
      cin >> car.time_to_light;
      car.time_to_light++;
    }

    if (verdict != "JAM") {
      // simulate
      if (command != -1) car.distance--;
      if (car.time_to_light > 0) car.time_to_light--;
    }

    int achived_order_count;
    cin >> achived_order_count;
    vector<int> achived_order_ids(achived_order_count);
    for (auto& id : achived_order_ids) {
      cin >> id;
      id--;
      orders.Achieve(id);
    }
  }
}
