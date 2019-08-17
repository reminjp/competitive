#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

struct Road {
  string id;
  int length;
  bool isOneWay;
  vector<int> nodeIndices;
  vector<int> seNodeIndices;
  vector<int> esNodeIndices;

  Road(string id, int length, bool isOneWay) : id(id), length(length), isOneWay(isOneWay) {}
};

struct Intersection {
  string id;
  set<pair<string, bool>> roads;
  vector<pair<pair<string, bool>, pair<string, bool>>> transitions;

  Intersection(string id) : id(id) {}
};

struct Node {
  string id;
  int position;
  bool isPark;
  bool isOpposite;

  Node(string id, int position) : id(id), position(position), isPark(false), isOpposite(false) {}
  Node(string id, int position, bool isPark, bool isOpposite)
      : id(id), position(position), isPark(isPark), isOpposite(isOpposite) {}
};

int main() {
  // ヘッダ
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  // 道路情報
  map<string, Road> roads;
  for (int i = 0; i < a; i++) {
    string id;
    int length, f;
    cin >> id >> length >> f;
    roads.insert({id, Road(id, length, f != 0)});
  }

  // 交差点情報
  map<string, Intersection> intersections;
  for (int i = 0; i < b; i++) {
    string id, ri, ro;
    cin >> id >> ri >> ro;
    char ci = ri[4], co = ro[4];
    ri.resize(4);
    ro.resize(4);
    if (!intersections.count(id)) {
      intersections.insert({id, Intersection(id)});
    }
    auto &intersection = intersections.at(id);
    intersection.roads.insert({ri, ci == 'E'});
    intersection.roads.insert({ro, co != 'E'});
    intersection.transitions.push_back({{ri, ci == 'E'}, {ro, co == 'E'}});
  }

  // 駐車可能箇所情報・配達先情報
  vector<Node> nodes;
  map<string, int> nodeIndicesMap;
  for (int i = 0; i < c; i++) {
    string id, r;
    int p;
    cin >> id >> r >> p;
    nodes.push_back(Node(id, p, true, id[4] == 'E'));
    roads.at(r).nodeIndices.push_back(nodes.size() - 1);
  }
  for (int i = 0; i < d; i++) {
    string id, r;
    int p;
    cin >> id >> r >> p;
    nodes.push_back(Node(id, p));
    roads.at(r).nodeIndices.push_back(nodes.size() - 1);
  }
  for (int i = 0; i < nodes.size(); i++) {
    nodeIndicesMap.insert({nodes[i].id, i});
  }
  for (auto &p : roads) {
    auto &road = p.second;

    // Add dummy nodes for empty roads
    nodes.push_back({road.id + "SE", 0, true, false});
    road.nodeIndices.push_back(nodes.size() - 1);
    nodes.push_back({road.id + "ES", 0, true, true});
    road.nodeIndices.push_back(nodes.size() - 1);

    sort(begin(road.nodeIndices), end(road.nodeIndices), [&nodes](int a, int b) {
      return nodes[a].position != nodes[b].position ? nodes[a].position < nodes[b].position : nodes[a].id < nodes[b].id;
    });

    for (int i : road.nodeIndices) {
      if (!nodes[i].isPark) continue;
      if (!nodes[i].isOpposite) {
        road.seNodeIndices.push_back(i);
      } else {
        road.esNodeIndices.push_back(i);
      }
    }
  }

  // Construct a adjacency matrix
  vector<vector<vector<int>>> adjacencyMatrix(nodes.size(), vector<vector<int>>(nodes.size(), vector<int>(2, INF)));
  for (int i = 0; i < adjacencyMatrix.size(); i++) adjacencyMatrix[i][i][0] = adjacencyMatrix[i][i][1] = 0;
  for (const auto &p : roads) {
    const auto &road = p.second;

    for (int i = 0; i + 1 < road.seNodeIndices.size(); i++) {
      adjacencyMatrix[road.seNodeIndices[i]][road.seNodeIndices[i + 1]][0] =
          abs(nodes[road.seNodeIndices[i + 1]].position - nodes[road.seNodeIndices[i]].position);

      // cerr << nodes[road.seNodeIndices[i]].id << " -> " << nodes[road.seNodeIndices[i + 1]].id << " "
      //      << adjacencyMatrix[road.seNodeIndices[i]][road.seNodeIndices[i + 1]][0] << endl;
    }
    for (int i = 0; i + 1 < road.esNodeIndices.size(); i++) {
      adjacencyMatrix[road.esNodeIndices[i + 1]][road.esNodeIndices[i]][0] =
          abs(nodes[road.esNodeIndices[i]].position - nodes[road.esNodeIndices[i + 1]].position);

      // cerr << nodes[road.esNodeIndices[i + 1]].id << " -> " << nodes[road.esNodeIndices[i]].id << " "
      //      << adjacencyMatrix[road.esNodeIndices[i + 1]][road.esNodeIndices[i]][0] << endl;
    }
    for (int i = 0; i + 1 < road.nodeIndices.size(); i++) {
      int x = road.nodeIndices[i];
      int y = road.nodeIndices[i + 1];
      adjacencyMatrix[x][y][1] = adjacencyMatrix[y][x][1] = abs(nodes[x].position - nodes[y].position);

      // cerr << nodes[x].id << " <-> " << nodes[y].id << " " << adjacencyMatrix[x][y][1] << endl;
    }
  }
  for (const auto &p : intersections) {
    const auto &intersection = p.second;

    for (const auto &t : intersection.transitions) {
      const auto &srcRoad = roads.at(t.first.first);
      const auto &dstRoad = roads.at(t.second.first);
      int srcNodeIndex = t.first.second ? srcRoad.esNodeIndices.front() : srcRoad.seNodeIndices.back();
      int dstNodeIndex = t.second.second ? dstRoad.esNodeIndices.back() : dstRoad.seNodeIndices.front();
      int srcNodePosition =
          t.first.second ? nodes[srcNodeIndex].position : srcRoad.length - nodes[srcNodeIndex].position;
      int dstNodePosition =
          t.second.second ? dstRoad.length - nodes[dstNodeIndex].position : nodes[dstNodeIndex].position;
      adjacencyMatrix[srcNodeIndex][dstNodeIndex][0] = srcNodePosition + dstNodePosition;

      // cerr << nodes[srcNodeIndex].id << " -> " << nodes[dstNodeIndex].id << " " << srcNodePosition + dstNodePosition
      //      << endl;
    }

    for (const auto &r1 : intersection.roads) {
      for (const auto &r2 : intersection.roads) {
        if (r1 == r2) continue;
        const auto &road1 = roads.at(r1.first);
        const auto &road2 = roads.at(r2.first);
        int nodeIndex1 = r1.second ? road1.nodeIndices.front() : road1.nodeIndices.back();
        int nodeIndex2 = r2.second ? road2.nodeIndices.front() : road2.nodeIndices.back();
        int nodePosition1 = r1.second ? nodes[nodeIndex1].position : road1.length - nodes[nodeIndex1].position;
        int nodePosition2 = r2.second ? nodes[nodeIndex2].position : road2.length - nodes[nodeIndex2].position;
        adjacencyMatrix[nodeIndex1][nodeIndex2][1] = adjacencyMatrix[nodeIndex2][nodeIndex1][1] =
            nodePosition1 + nodePosition2;

        // cerr << nodes[nodeIndex1].id << " <-> " << nodes[nodeIndex2].id << " " << nodePosition1 + nodePosition2 <<
        // endl;
      }
    }
  }

  // Warshall-Floyd algorithm
  const int n = nodes.size();
  // vector<vector<vector<int>>> next(n, vector<vector<int>>(n, vector<int>(2)));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     for (int q = 0; q < 2; q++) {
  //       next[i][j][q] = j;
  //     }
  //   }
  // }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int q = 0; q < 2; q++) {
          if (adjacencyMatrix[i][j][q] > adjacencyMatrix[i][k][q] + adjacencyMatrix[k][j][q]) {
            adjacencyMatrix[i][j][q] = adjacencyMatrix[i][k][q] + adjacencyMatrix[k][j][q];
            // next[i][j][q] = next[i][k][q];
          }
        }
      }
    }
  }

  // クエリ
  for (int i = 0; i < e; i++) {
    int q;
    string xs, ys;
    cin >> q >> xs >> ys;
    int x = nodeIndicesMap.at(xs), y = nodeIndicesMap.at(ys);
    cout << (adjacencyMatrix[x][y][q] != INF ? adjacencyMatrix[x][y][q] : -1) << endl;

    // for (int i = x; i != y; i = next[i][y][q]) cout << nodes[i].id << ' ';
    // cout << nodes[y].id << endl;
  }
}
