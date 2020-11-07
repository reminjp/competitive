#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
constexpr int M = 20, C = 100;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
const string i_to_c = "ULDR";
int c_to_i[256];

inline int RandomTerm(int term) { return rand() % term; }

inline int RandomMinTerm(int min, int term) { return min + rand() % (term - min); }

struct Position {
  int x, y;
  Position() : Position(0, 0) {}
  Position(int x, int y) : x(x), y(y) {}

  int Distance(int x, int y) const { return abs(this->x - x) + abs(this->y - y); }
  int Distance(const Position& other) const { return Distance(other.x, other.y); }

  pair<int, int> ToPair() { return make_pair(x, y); }
};

struct Card : Position {
  int i;
  Card() : Card(0, 0, 0) {}
  Card(int x, int y, int i) : Position(x, y), i(i) {}
};

vector<Position> near_poss;

struct Simulation {
  int cost;
  string command;

  Simulation(const vector<Card>& cards, const vector<int>& path, bool verbose = false) {
    vector<int> stack;
    vector m(M, vector<int>(M, -1));
    for (auto e : cards) m[e.y][e.x] = e.i;

    cost = 0;
    Position pos(0, 0);
    for (auto e : path) {
      // cerr << e << endl;

      auto it = lower_bound(stack.begin(), stack.end(), e);
      vector<Card> t;
      if (it != stack.end()) {
        for (int i = 0, s = stack.end() - it; t.size() < s;) {
          Position p;
          for (;; i++) {
            if (i >= near_poss.size()) {
              cost = INF;
              return;
            }
            p = Position(cards[e].x + near_poss[i].x, cards[e].y + near_poss[i].y);
            if (unsigned(p.x) >= M || unsigned(p.y) >= M) continue;
            if (m[p.y][p.x] == -1) break;
          }
          i++;
          t.push_back(Card(p.x, p.y, -1));
        }
      }

      for (int i = (int)t.size() - 1; i >= 0; i--) {
        cost += pos.Distance(t[i]);
        if (verbose) {
          while (pos.y > t[i].y) pos.y--, command.push_back('L');
          while (pos.y < t[i].y) pos.y++, command.push_back('R');
          while (pos.x > t[i].x) pos.x--, command.push_back('U');
          while (pos.x < t[i].x) pos.x++, command.push_back('D');
          command.push_back('O');
        } else {
          pos = t[i];
        }
        t[i].i = stack.back();
        stack.pop_back();
      }

      // if (t.size()) {
      //   for (auto e : t) cerr << "(" << e.x << ", " << e.y << ", " << e.i << ") ";
      //   cerr << endl;
      // }

      cost += pos.Distance(cards[e]);
      if (verbose) {
        while (pos.y > cards[e].y) pos.y--, command.push_back('L');
        while (pos.y < cards[e].y) pos.y++, command.push_back('R');
        while (pos.x > cards[e].x) pos.x--, command.push_back('U');
        while (pos.x < cards[e].x) pos.x++, command.push_back('D');
        command.push_back('I');
        m[pos.y][pos.x] = -1;
      } else {
        pos = cards[e];
      }
      stack.push_back(e);

      for (int i = 0; i < t.size(); i++) {
        cost += pos.Distance(t[i]);
        if (verbose) {
          while (pos.y > t[i].y) pos.y--, command.push_back('L');
          while (pos.y < t[i].y) pos.y++, command.push_back('R');
          while (pos.x > t[i].x) pos.x--, command.push_back('U');
          while (pos.x < t[i].x) pos.x++, command.push_back('D');
          command.push_back('I');
        } else {
          pos = t[i];
        }
        stack.push_back(t[i].i);
      }

      // for (auto e : stack) cerr << e << ' ';
      // cerr << endl;
    }
  }
};

int main() {
  // setup
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  srand(0);

  for (int i = 0; i < 4; i++) c_to_i[i_to_c[i]] = i;

  {
    set<pair<int, int>> visited{{0, 0}};
    Position pos;
    int d = 3;
    while (near_poss.size() < 4 * C) {
      Position left_pos(pos.x + dx[(d + 1) % 4], pos.y + dy[(d + 1) % 4]);
      if (visited.count(left_pos.ToPair())) {
        Position front_pos(pos.x + dx[d], pos.y + dy[d]);
        visited.insert(front_pos.ToPair());
        pos = front_pos;
      } else {
        visited.insert(left_pos.ToPair());
        pos = left_pos;
        d = (d + 1) % 4;
      }
      near_poss.push_back(pos);
    }
    // for (auto e : near_poss) cerr << "(" << e.x << ", " << e.y << ") ";
    // cerr << endl;
  }

  // input
  vector<Card> cards(C);
  for (int i = 0; i < C; i++) {
    cards[i].i = i;
    cin >> cards[i].x >> cards[i].y;
  }

  // solve
  // initial slution
  vector<int> path;
  {
    Position pos;
    vector<bool> is_visited(C);
    while (path.size() < C) {
      int nearest_i = -1;
      for (int i = 0; i < C; i++) {
        if (is_visited[i]) continue;
        // if (nearest_i == -1 || pos.Distance(cards[i]) < pos.Distance(cards[nearest_i])) {
        if (nearest_i == -1) {
          nearest_i = i;
        }
      }
      assert(nearest_i != -1);
      path.push_back(nearest_i);
      pos = cards[nearest_i];
      is_visited[nearest_i] = true;
    }
  }

  // optimize
  int min_cost;
  {
    auto s = Simulation(cards, path);
    min_cost = s.cost;
  }
  for (int iteration = 0; iteration < 1e5; iteration++) {
    int l = RandomTerm(C - 1);
    // int r = RandomMinTerm(l + 2, C + 1);
    int r = RandomMinTerm(l + 2, min(l + 10, C + 1));
    reverse(path.begin() + l, path.begin() + r);
    // int l = RandomTerm(C - 1);
    // int r = RandomMinTerm(l + 1, min(l + 10, C));
    // swap(path[l], path[r]);

    auto s = Simulation(cards, path);
    int cost = s.cost;

    if (cost < min_cost) {
      min_cost = cost;
    } else {
      reverse(path.begin() + l, path.begin() + r);
      // swap(path[l], path[r]);
    }
  }

  // output
  auto simulation = Simulation(cards, path, true);
  cerr << "cost: " << simulation.cost << endl;
  cerr << "score: " << 4000 - simulation.cost << endl;
  cout << simulation.command << endl;
}
