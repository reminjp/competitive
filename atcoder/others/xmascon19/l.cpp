#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

std::string ReadFile(std::string filename) {
  FILE *f = fopen(filename.c_str(), "r");
  if (f == nullptr) perror("error");
  char buffer[1024];
  std::string s;
  while (!feof(f)) {
    if (fgets(buffer, 1024, f) == NULL) break;
    s += (std::string)(buffer);
  }
  fclose(f);
  return s;
}

int main() {
  stringstream ss;

  ss << ReadFile("a.txt");
  vector<vector<int>> a(8, vector<int>(8));
  for (auto &ai : a) {
    for (auto &e : ai) ss >> e;
    reverse(ai.begin(), ai.end());
  }

  vector<string> words;
  words.push_back("xmas");
  words.push_back("contest");
  for (const auto &ai : a) {
    vector<string> s(32);
    for (auto e : ai) {
      ss << ReadFile("signboard_t2/pieces_back/" + to_string(e) + ".txt");
      for (int i = 0; i < s.size(); i++) {
        string t;
        ss >> t;
        s[i] += t;
      }
    }
    for (const auto &si : s) {
      string t;
      for (auto e : si) {
        if (e == '.') {
          if (!t.empty()) {
            words.push_back(t);
            t.clear();
          }
        } else {
          t.push_back(e);
        }
      }
      if (!t.empty()) words.push_back(t);
    }
  }

  ss << ReadFile("signboard_t2/skeleton.txt");
  vector<string> skeleton(14);
  for (auto &e : skeleton) ss >> e;
  struct Blank {
    int y1, x1, y2, x2;
  };
  vector<Blank> blanks;
  for (int y = 0; y < 14; y++) {
    int x1 = 0, x2 = 0;
    for (int x = 0; x < 14; x++) {
      if (skeleton[y][x] != '.') {
        x2 = x;
      }
      if (skeleton[y][x] == '.' || x == 14 - 1) {
        if (x2 - x1 > 1) blanks.push_back({y, x1, y, x2});
        x1 = x + 1;
      }
    }
  }
  for (int x = 0; x < 14; x++) {
    int y1 = 0, y2 = 0;
    for (int y = 0; y < 14; y++) {
      if (skeleton[y][x] == '*') {
        y2 = y;
      }
      if (skeleton[y][x] == '.' || y == 14 - 1) {
        if (y2 - y1 > 1) blanks.push_back({y1, x, y2, x});
        y1 = y + 1;
      }
    }
  }

  vector<int> lengths(blanks.size());
  struct Intersection {
    int to, from_pos, to_pos;
  };
  vector<vector<Intersection>> intersections(blanks.size());
  for (int i = 0; i < blanks.size(); i++) {
    bool is_blank_i_horizontal = blanks[i].y1 == blanks[i].y2;
    lengths[i] = is_blank_i_horizontal ? blanks[i].x2 - blanks[i].x1 + 1 : blanks[i].y2 - blanks[i].y1 + 1;
    if (is_blank_i_horizontal) {
      for (int j = 0; j < blanks.size(); j++) {
        if (blanks[j].y1 == blanks[j].y2) continue;
        if (blanks[j].x1 < blanks[i].x1 || blanks[i].x2 < blanks[j].x1) continue;
        if (blanks[i].y1 < blanks[j].y1 || blanks[j].y2 < blanks[i].y1) continue;
        int from_pos = blanks[j].x1 - blanks[i].x1;
        int to_pos = blanks[i].y1 - blanks[j].y1;
        intersections[i].push_back({j, from_pos, to_pos});
        intersections[j].push_back({i, to_pos, from_pos});
      }
    }
  }

  vector<int> order;
  auto dfs2 = [&](auto &&dfs2, int i, int j) -> void {
    order.push_back(j);
    for (auto e : intersections[j]) {
      if (e.to == i) continue;
      dfs2(dfs2, j, e.to);
    }
  };
  dfs2(dfs2, 0, 0);
  {
    auto blanks2 = blanks;
    for (int i = 0; i < blanks.size(); i++) blanks[i] = blanks2[order[i]];
  }

  vector<bool> used(words.size());
  auto dfs = [&](auto &&dfs, int b) -> bool {
    if (b >= blanks.size()) {
      return true;
    }

    for (int w = 0; w < words.size(); w++) {
      if (used[w]) continue;
      int l = (blanks[b].x2 - blanks[b].x1) + (blanks[b].y2 - blanks[b].y1) + 1;
      if (l != words[w].size()) continue;

      bool valid = true;
      string prev_blank;
      for (int i = 0; i < l; i++) {
        int y = blanks[b].y1 + i * (blanks[b].y1 != blanks[b].y2);
        int x = blanks[b].x1 + i * (blanks[b].x1 != blanks[b].x2);
        if (skeleton[y][x] == '*' || skeleton[y][x] == words[w][i]) {
          prev_blank.push_back(skeleton[y][x]);
          skeleton[y][x] = words[w][i];
        } else {
          valid = false;
          break;
        }
      }
      if (valid) {
        used[w] = true;
        if (dfs(dfs, b + 1)) return true;
        used[w] = false;
      }
      for (int i = 0; i < prev_blank.size(); i++) {
        int y = blanks[b].y1 + i * (blanks[b].y1 != blanks[b].y2);
        int x = blanks[b].x1 + i * (blanks[b].x1 != blanks[b].x2);
        skeleton[y][x] = prev_blank[i];
      }
    }

    return false;
  };
  dfs(dfs, 0);

  for (const auto &e : skeleton) cout << e << endl;
}
