#include <bits/stdc++.h>
using namespace std;

const string MOVE = "MOVE";
const string SURFACE = "SURFACE";
const string TORPEDO = "TORPEDO";

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const string direction_int_to_char = "SENW";

inline int RandTerm(int term) { return rand() % term; }

inline int RandMinTerm(int min, int term) { return min + rand() % (term - min); }

int main() {
  // first turn
  // input
  int W, H, player_id;
  cin >> W >> H >> player_id;
  vector<string> stage(H);
  for (auto& e : stage) cin >> e;

  // output
  while (true) {
    int x = RandTerm(W);
    int y = RandTerm(H);
    if (stage[y][x] == '.') {
      cout << x << ' ' << y << endl;
      break;
    }
  }

  vector<vector<bool>> visited(H, vector<bool>(W));

  // each turn
  while (cin) {
    // inpu
    // line 1
    int x, y, player_life, opponent_life;
    int torpedo_cooldown, sonar_cooldown, silence_cooldown, mine_cooldown;
    cin >> x >> y >> player_life >> opponent_life;
    cin >> torpedo_cooldown >> sonar_cooldown >> silence_cooldown >> mine_cooldown;
    // line 2
    string sonar_result;
    cin >> sonar_result;
    cin.ignore();
    // line 3
    string opponent_orders;
    getline(cin, opponent_orders);
    // string opponent_move_direction;
    // int opponent_surface_sector, opponent_torpedo_x, opponent_torpedo_y;
    // if (opponent_order == MOVE) {
    //   cin >> opponent_move_direction;
    // } else if (opponent_order == SURFACE) {
    //   cin >> opponent_surface_sector;
    // } else if (opponent_order == TORPEDO) {
    //   cin >> opponent_torpedo_x >> opponent_torpedo_y;
    // }

    visited[y][x] = true;

    // output
    while (true) {
      int d = RandTerm(4);
      int x2 = x + dx[d], y2 = y + dy[d];
      if (unsigned(x2) < W && unsigned(y2) < H && stage[y2][x2] == '.' && !visited[y2][x2]) {
        cout << "MOVE " << direction_int_to_char[d] << " TORPEDO" << endl;
        break;
      }
    }
  }
}
