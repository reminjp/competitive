// remin's Nodeless Solver (C) 2018 remin
// v1.0.0

#include <bits/stdc++.h>
#include "json.hpp"

// #define DEBUG_PRINT

class union_find {
 private:
  std::vector<int> parent;
  std::vector<int> rank;
  std::vector<int> sizes;

 public:
  union_find(int n) : parent(n), rank(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      parent[a] = b;
    } else {
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
    sizes[find(a)] = sizes[a] + sizes[b];
  }
  int find(int a) { return parent[a] == a ? a : parent[a] = find(parent[a]); }
  int size(int a) { return sizes[find(a)]; }
};

void remove_newline(std::string& s) {
  std::string target("\n");
  std::string::size_type pos = s.find(target);
  while (pos != std::string::npos) {
    s.replace(pos, target.size(), "");
    pos = s.find(target, pos);
  }
}

struct Node {
  std::vector<int> neighbors;
  int index;
  int player;
  int count;

  Node() : Node(0, -1, 0) {}
  Node(int index, int player, int count) : index(index), player(player), count(count) {}
};

struct Graph {
  std::vector<Node> nodes;

  Graph() : Graph(0) {}
  Graph(int size) { nodes = std::vector<Node>(size); }
  int size() const { return static_cast<int>(nodes.size()); }
  void add_edge(const int a, const int b) {
    nodes[a].neighbors.push_back(b);
    nodes[b].neighbors.push_back(a);
  }
};

struct Action {
  int src;
  int dst;
  int count;

  Action(int src, int dst, int count) : src(src), dst(dst), count(count) {}
};

class Solver {
 public:
  Solver();
  ~Solver();
  std::vector<int> initialize(const Graph& graph, const int uid, const int unit_count);
  Action update(const Graph& graph);
  void finalize();

 private:
  int uid;
};

Solver::Solver() {}

Solver::~Solver() {}

std::vector<int> Solver::initialize(const Graph& graph, const int uid, const int unit_count) {
  this->uid = uid;

  std::vector<int> positions;

  std::vector<std::pair<int, int>> neighbor_counts;
  for (const auto& node : graph.nodes) {
    neighbor_counts.push_back({node.neighbors.size(), node.index});
  }
  std::sort(std::begin(neighbor_counts), std::end(neighbor_counts));
  // auto it = std::upper_bound(std::begin(neighbor_counts), std::end(neighbor_counts), std::make_pair(unit_count, 0));
  // if (it != std::begin(neighbor_counts)) it--;
  // const auto& node_to_keep = graph.nodes[it->second];
  const auto& node_to_keep = graph.nodes[neighbor_counts.front().second];
  for (int i = 0; i < unit_count; i++) {
    positions.push_back(node_to_keep.neighbors[i % node_to_keep.neighbors.size()]);
  }

  std::sort(std::begin(positions), std::end(positions));
  return positions;
}

Action Solver::update(const Graph& graph) {
  const int n = graph.size();

  std::vector<int> empty_neighbor_count(n);
  for (int i = 0; i < n; i++) {
    for (auto e : graph.nodes[i].neighbors) {
      empty_neighbor_count[i] += graph.nodes[e].player == -1;
    }
  }

  std::vector<int> reachable_node_count(n);
  {
    union_find uf(n);
    for (int i = 0; i < n; i++) {
      if (graph.nodes[i].player != -1) continue;
      for (auto e : graph.nodes[i].neighbors) {
        if (graph.nodes[e].player != -1) continue;
        uf.unite(i, e);
      }
    }
    for (const auto& node : graph.nodes) {
      union_find uf2 = uf;
      for (int i : node.neighbors) {
        uf2.unite(node.index, i);
      }
      reachable_node_count[node.index] = uf2.size(node.index) - 1;
    }
  }

  std::vector<int> scores(n);
  for (int i = 0; i < n; i++) {
    scores[i] += empty_neighbor_count[i];
    scores[i] += n * reachable_node_count[i];
  }

  Action action(-1, -1, -1);
  {
    std::pair<int, int> max_score = {0, 0};
    for (int i = 0; i < n; i++) {
      if (!(graph.nodes[i].player == this->uid && graph.nodes[i].count > 0)) continue;
      for (int j : graph.nodes[i].neighbors) {
        if (graph.nodes[j].player != -1) continue;
        std::pair<int, int> score = {scores[j], -scores[i]};
        if (score > max_score) {
          max_score = score;
          action = Action(i, j, graph.nodes[i].count);
        }
      }
    }
  }

  return action;
}

void Solver::finalize() {}

int main() {
  Solver* solver = new Solver();
  Graph graph;
  std::string name;

  while (true) {
    std::string s;
    getline(std::cin, s);
    nlohmann::json input = nlohmann::json::parse(s);
    nlohmann::json output;
    auto action = input["action"];

    if (action == "quit") {
      solver->finalize();
      std::cout << std::endl;
      break;
    }

    auto nodes = input["nodes"];
    auto edges = input["edges"];
    auto state = input["state"];
    auto units = input["units"];

    if (action == "init") {
      graph = Graph(nodes.size());
      for (int i = 0; i < graph.size(); i++) {
        graph.nodes[i].index = i;
      }
      for (const auto& edge : edges) {
        graph.add_edge(edge[0], edge[1]);
      }
    }
    for (int i = 0; i < graph.size(); i++) {
      graph.nodes[i].player = state[i];
      graph.nodes[i].count = units[i];
    }

    if (action == "play") {
      auto action = solver->update(graph);

      output["src"] = action.src;
      output["dst"] = action.dst;
      output["num"] = action.count;
#ifdef DEBUG_PRINT
      std::cerr << name << ": " << output << std::endl;
#endif
    } else if (action == "init") {
      int uid = input["uid"];
      auto num_units = input["num_units"];
      name = input["names"][uid];

      std::vector<int> positions = solver->initialize(graph, uid, num_units);
      output["positions"] = positions;
    }

    s = output.dump();
    remove_newline(s);
    std::cout << s << std::endl;
  }

  delete solver;
  return 0;
}
