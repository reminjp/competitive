#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const string direction_int_to_char = "URDL";
map<char, int> direction_char_to_int;

struct Position {
  int y, x;
};

struct Command {
  char c;
  Position pos1, pos2;
};

Position next_position(const vector<vector<bool>>& pillar, Position pos, char c) {
  int d = direction_char_to_int[c];
  while (true) {
    int y = pos.y + dy[d];
    int x = pos.x + dx[d];
    if ((unsigned)y >= pillar.size() || (unsigned)x >= pillar[y].size() || pillar[y][x]) break;
    pos.y = y;
    pos.x = x;
  }
  return pos;
}

int main() {
  for (int i = 0; i < direction_int_to_char.size(); i++) direction_char_to_int[direction_int_to_char[i]] = i;

  int N, P, M;
  cin >> N >> P >> M;
  Position start;
  vector<vector<bool>> pillar(N, vector<bool>(N));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) {
      if (s[j] == 'o') {
        start.y = i;
        start.x = j;
      } else if (s[j] == 'x') {
        pillar[i][j] = true;
      }
    }
  }
  vector<string> sheet(N);
  for (auto& e : sheet) cin >> e;

  vector<Command> commands;

  Position pos = start;
  vector<vector<bool>> visited(N, vector<bool>(N));

  Position last_pillar_pos{N - 1, N - 1};
  auto command_pillar = [&](const Position& p) {
    if (last_pillar_pos.y == p.y && last_pillar_pos.x == p.x) return;
    commands.push_back(Command{'P', last_pillar_pos.y, last_pillar_pos.x, p.y, p.x});
    pillar[last_pillar_pos.y][last_pillar_pos.x] = false;
    pillar[p.y][p.x] = true;
    last_pillar_pos = p;
  };
  auto command_move = [&](char c) {
    commands.push_back(Command{c});
    pos = next_position(pillar, pos, c);
    visited[pos.y][pos.x] = true;
  };

  if (sheet[pos.y][pos.x] == 'Z') {
    command_move('D');
  }

  int t = 0;
  for (int l = 0, r = N * N - 1; l < r; l++, r--) {
    while (l < r && !pillar[l / N][l % N]) l++;
    while (l < r && (pillar[r / N][r % N] || (r / N == pos.y && r % N == pos.x))) r--;
    if (!(l < r)) break;
    commands.push_back(Command{'P', l / N, l % N, r / N, r % N});
    pillar[l / N][l % N] = false;
    pillar[r / N][r % N] = true;
    t = r;
  }

  for (char c = 'Z'; c >= 'A' && commands.size() < M; c--) {
    for (int i = 0; i < N; i++) {
      if (pillar[i][pos.x] && !(last_pillar_pos.y == i && last_pillar_pos.x == pos.x)) break;
      if (visited[i][pos.x] || sheet[i][pos.x] != c) continue;

      if (i < pos.y) {
        if (last_pillar_pos.y == i - 1 && last_pillar_pos.x == pos.x) {
          // no need to move
        } else if (i == 0) {
          if (i <= last_pillar_pos.y && last_pillar_pos.y < pos.y && last_pillar_pos.x == pos.x)
            command_pillar(Position{N - 1, N - 1});
        } else {
          command_pillar(Position{i - 1, pos.x});
        }
        command_move('U');
      } else if (i > pos.y) {
        if (last_pillar_pos.y == i + 1 && last_pillar_pos.x == pos.x) {
          // no need to move
        } else if (i == N - 1 || pillar[i + 1][pos.x]) {
          if (pos.y < last_pillar_pos.y && last_pillar_pos.y <= i && last_pillar_pos.x == pos.x)
            command_pillar(Position{N - 1, N - 1});
        } else {
          command_pillar(Position{i + 1, pos.x});
        }
        command_move('D');
      } else {
        // assert
      }
    }
  }

  vector<vector<vector<int>>> cxs(26, vector<vector<int>>(N));
  for (int i = 0; i < t; i++) cxs[sheet[i / N][i % N] - 'A'][i / N].push_back(i % N);

  for (char c = 'A'; c <= 'Z' && commands.size() < M; c++) {
    for (int i = 0; i < N; i++) {
      if (pillar[i][pos.x] && !(last_pillar_pos.y == i && last_pillar_pos.x == pos.x)) break;
      if (cxs[c - 'A'][i].size() == 0 || (cxs[c - 'A'][i].size() == 1 && cxs[c - 'A'][i].front() == start.x)) continue;

      // same as above
      if (i < pos.y) {
        if (last_pillar_pos.y == i - 1 && last_pillar_pos.x == pos.x) {
          // no need to move
        } else if (i == 0) {
          if (i <= last_pillar_pos.y && last_pillar_pos.y < pos.y && last_pillar_pos.x == pos.x)
            command_pillar(Position{N - 1, N - 1});
        } else {
          command_pillar(Position{i - 1, pos.x});
        }
        command_move('U');
      } else if (i > pos.y) {
        if (last_pillar_pos.y == i + 1 && last_pillar_pos.x == pos.x) {
          // no need to move
        } else if (i == N - 1 || pillar[i + 1][pos.x]) {
          if (pos.y < last_pillar_pos.y && last_pillar_pos.y <= i && last_pillar_pos.x == pos.x)
            command_pillar(Position{N - 1, N - 1});
        } else {
          command_pillar(Position{i + 1, pos.x});
        }
        command_move('D');
      } else {
        // assert
      }

      // row
      for (auto j : cxs[c - 'A'][i]) {
        if (visited[i][j]) continue;

        if (j < pos.x) {
          if (last_pillar_pos.y == pos.y && last_pillar_pos.x == j - 1) {
            // no need to move
          } else if (j == 0) {
            if (last_pillar_pos.y == pos.y && j <= last_pillar_pos.x && last_pillar_pos.x < pos.x)
              command_pillar(Position{N - 1, N - 1});
          } else {
            command_pillar(Position{i, j - 1});
          }
          command_move('L');
        } else if (j > pos.x) {
          if (last_pillar_pos.y == pos.y && last_pillar_pos.x == j + 1) {
            // no need to move
          } else if (j == N - 1 || pillar[i][j + 1]) {
            if (last_pillar_pos.y == pos.y && pos.x < last_pillar_pos.x && last_pillar_pos.x <= j)
              command_pillar(Position{N - 1, N - 1});
          } else {
            command_pillar(Position{i, j + 1});
          }
          command_move('R');
        } else {
          // assert
        }
      }

      // return to start.x
      if (start.x < pos.x) {
        if (last_pillar_pos.y == pos.y && last_pillar_pos.x == start.x - 1) {
          // no need to move
        } else if (start.x == 0) {
          if (last_pillar_pos.y == pos.y && start.x <= last_pillar_pos.x && last_pillar_pos.x < pos.x)
            command_pillar(Position{N - 1, N - 1});
        } else {
          command_pillar(Position{i, start.x - 1});
        }
        command_move('L');
      } else if (start.x > pos.x) {
        if (last_pillar_pos.y == pos.y && last_pillar_pos.x == start.x + 1) {
          // no need to move
        } else if (start.x == N - 1 || pillar[i][start.x + 1]) {
          if (last_pillar_pos.y == pos.y && pos.x < last_pillar_pos.x && last_pillar_pos.x <= start.x)
            command_pillar(Position{N - 1, N - 1});
        } else {
          command_pillar(Position{i, start.x + 1});
        }
        command_move('R');
      } else {
        // assert
      }
    }
  }

  if (commands.size() > M) commands.resize(M);
  for (auto e : commands) {
    cout << e.c;
    if (e.c == 'P') cout << ' ' << e.pos1.y << ' ' << e.pos1.x << ' ' << e.pos2.y << ' ' << e.pos2.x;
    cout << '\n';
  }
  cout << flush;
}
