#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;
constexpr int STORE = 0;

inline int RandTerm(int term) { return rand() % term; }

inline int RandMinTerm(int min, int term) { return min + rand() % (term - min); }

struct Order {
  int t, n, id, dst;
  bool is_ordered, is_put, is_achieved;
};

istream& operator>>(istream& is, Order& order) {
  is >> order.n;
  if (order.n) {
    is >> order.id >> order.dst;
    order.dst--;
  }
  return is;
}

struct Command {
  int raw;
};

ostream& operator<<(ostream& os, const Command& command) {
  os << command.raw + (command.raw != -1);
  return os;
}

struct Position {
  int u, v, du, dv;
};

struct Graph {
  int n;
  vector<vector<int>> adjacency_matrix, distance_matrix, next_node_matrix;

  Graph(int n)
      : n(n),
        adjacency_matrix(n, vector<int>(n, INF)),
        distance_matrix(n, vector<int>(n, INF)),
        next_node_matrix(n, vector<int>(n)) {
    for (int i = 0; i < n; i++) distance_matrix[i][i] = 0;
    for (auto& e : next_node_matrix) iota(e.begin(), e.end(), 0);
  }

  void AddEdge(int u, int v, int d) {
    adjacency_matrix[u][v] = adjacency_matrix[v][u] = d;
    distance_matrix[u][v] = distance_matrix[v][u] = d;
  }

  void Preprocess() {
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

  inline int Distance(int i, int j) { return distance_matrix[i][j]; }

  inline int Distance(const Position& p, int i) {
    return min(distance_matrix[p.u][i] + p.du, distance_matrix[p.v][i] + p.dv);
  }

  Command CalculateCommand(const Position& position, const int destination_node) {
    if (position.du == 0 || position.dv == 0) {
      int i = position.du == 0 ? position.u : position.v;
      if (i == destination_node) return Command{-1};
      int j = next_node_matrix[i][destination_node];
      return Command{j};
    }
    int du = position.du + distance_matrix[position.u][destination_node];
    int dv = position.dv + distance_matrix[position.v][destination_node];
    return Command{du <= dv ? position.u : position.v};
  }

  bool SimulateCommand(Position& position, const Command& command) {
    if (command.raw == -1) return true;
    if (position.u == command.raw) {
      if (position.du == 0) return false;
      position.du--;
      position.dv++;
      return true;
    }
    if (position.v == command.raw) {
      if (position.dv == 0) return false;
      position.du++;
      position.dv--;
      return true;
    }
    if (position.du == 0) {
      if (adjacency_matrix[position.u][command.raw] == INF) return false;
      position = {position.u, command.raw, 1, adjacency_matrix[position.u][command.raw] - 1};
      return true;
    }
    if (position.dv == 0) {
      if (adjacency_matrix[position.v][command.raw] == INF) return false;
      position = {position.v, command.raw, 1, adjacency_matrix[position.v][command.raw] - 1};
      return true;
    }
    return false;
  }
};

int main() {
  // setup
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  srand(0);

  // input
  int V, E, T;
  cin >> V >> E;
  Graph graph(V);
  for (int i = 0; i < E; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    graph.AddEdge(u - 1, v - 1, d);
  }
  cin >> T;
  vector<Order> orders(T);
  for (int i = 0; i < T; i++) {
    Order order;
    cin >> order;
    if (order.n) {
      order.t = i;
      orders[order.id - 1] = order;
    }
  }

  // solve
  graph.Preprocess();

  Position position{STORE, STORE, 0, 0};

  vector<int> route;

  int ordered_count = 0, put_count = 0;
  bool should_ignore_last_orders = false;

  for (int t = 0; t < T; t++) {
    // input
    Order order;
    auto it = find_if(orders.begin(), orders.end(), [t](const Order& e) { return e.id && e.t == t; });
    if (it != orders.end()) {
      order = *it;
      it->is_ordered = true;
      ordered_count++;
    }

    vector<int> put_ids;
    if (graph.Distance(position, STORE) == 0) {
      for (auto& e : orders) {
        if (!e.is_ordered) continue;

        e.is_ordered = false;
        e.is_put = true;
        ordered_count--;
        put_count++;

        put_ids.push_back(e.id);
      }
    }
    int n_put = put_ids.size();

    // solve
    bool should_update_route = false;

    if (n_put > 0) {
      for (auto e : put_ids) {
        if (find(route.begin(), route.end(), orders[e - 1].dst) != route.end()) continue;
        route.push_back(orders[e - 1].dst);
        should_update_route = true;
      }
    }

    if (should_update_route) {
      // traveling salesman problem
      for (int i = 0, p = STORE; i < route.size(); i++) {
        for (int j = i + 1; j < route.size(); j++) {
          if (graph.Distance(p, route[i]) > graph.Distance(p, route[j])) swap(route[i], route[j]);
        }
        p = route[i];
      }

      int min_cost = 0;
      min_cost += graph.Distance(STORE, route.front());
      min_cost += graph.Distance(route.back(), STORE);
      for (int i = 0; i + 1 < route.size(); i++) min_cost += graph.Distance(route[i], route[i + 1]);

      for (int iteration = 0; iteration < (int)3e7; iteration++) {
        int l = RandTerm(route.size());
        int r = RandMinTerm(l + 1, route.size() + 1);

        int next_cost = min_cost;
        if (l == 0) {
          next_cost -= graph.Distance(STORE, route[l]);
          next_cost += graph.Distance(STORE, route[r - 1]);
        } else {
          next_cost -= graph.Distance(route[l - 1], route[l]);
          next_cost += graph.Distance(route[l - 1], route[r - 1]);
        }
        if (r == route.size()) {
          next_cost -= graph.Distance(route[r - 1], STORE);
          next_cost += graph.Distance(route[l], STORE);
        } else {
          next_cost -= graph.Distance(route[r - 1], route[r]);
          next_cost += graph.Distance(route[l], route[r]);
        }

        if (next_cost < min_cost) {
          min_cost = next_cost;
          reverse(route.begin() + l, route.begin() + r);
        }
      }

      ll score_from_front = 0, score_from_back = 0;
      {
        int s = t, i = STORE;
        for (auto j : route) {
          s += graph.Distance(i, j);
          i = j;
          if (s >= T) break;
          for (const auto& e : orders) {
            if (e.is_put && e.dst == i) {
              ll w = s - e.t;
              score_from_front += T * T - w * w;
            }
          }
        }
      }
      reverse(route.begin(), route.end());
      {
        int s = t, i = STORE;
        for (auto j : route) {
          s += graph.Distance(i, j);
          i = j;
          if (s >= T) break;
          for (const auto& e : orders) {
            if (e.is_put && e.dst == i) {
              ll w = s - e.t;
              score_from_back += T * T - w * w;
            }
          }
        }
      }
      if (score_from_front > score_from_back) {
        reverse(route.begin(), route.end());
      }
    }

    // output
    Command command{-1};
    int destination = route.empty() ? STORE : route.front();

    if (!should_ignore_last_orders && t + graph.Distance(position, STORE) >= int(0.95 * T) - 1) {
      if (ordered_count < put_count) {
        should_ignore_last_orders = true;
      } else if (ordered_count > 0) {
        destination = STORE;
      }
    }

    command = graph.CalculateCommand(position, destination);
    graph.SimulateCommand(position, command);

    cout << command << endl;

    // input
    for (auto& e : orders) {
      if (graph.Distance(position, e.dst) != 0) continue;

      e.is_put = false;
      e.is_achieved = true;
      put_count--;

      auto it = find(route.begin(), route.end(), e.dst);
      if (it != route.end()) route.erase(it);
    }
  }
}
