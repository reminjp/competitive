#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> t{".###..#..###.###.#.#.###.###.###.###.###.", ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
                   ".#.#..#..###.###.###.###.###...#.###.###.", ".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
                   ".###.###.###.###...#.###.###...#.###.###."};

  int n;
  vector<string> s(5);
  cin >> n;
  for (auto& e : s) cin >> e;

  string r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      bool eq = true;
      for (int k = 0; k < 5; k++) eq = eq && s[k].substr(4 * i, 4) == t[k].substr(4 * j, 4);
      if (eq) {
        r.push_back('0' + j);
        break;
      }
    }
  }
  cout << r << endl;
}
