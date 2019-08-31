#include <bits/stdc++.h>
using namespace std;
constexpr int TIME_LIMIT = 3000;

class Timer {
 public:
  Timer() : time_begin(Now()) {}
  int Elapsed() { return chrono::duration_cast<chrono::milliseconds>(Now() - time_begin).count(); }

 private:
  chrono::system_clock::time_point time_begin;
  static chrono::system_clock::time_point Now() { return chrono::system_clock::now(); }
};

int main() {
  Timer timer;

  // input
  int n;
  vector<int> b(3);
  cin >> n;
  for (auto& e : b) cin >> e;
  vector<vector<int>> l(n, vector<int>(n)), r(n, vector<int>(n)), a(n, vector<int>(n));
  for (auto& ev : l) {
    for (auto& e : ev) cin >> e;
  }
  for (auto& ev : r) {
    for (auto& e : ev) cin >> e;
  }

  // greedy
  vector<pair<int, pair<int, int>>> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p.push_back({abs(i - n / 2) + abs(j - n / 2), {i, j}});
    }
  }
  sort(begin(p), end(p));
  // int score = 0;
  for (const auto& e : p) {
    int ei = e.second.first, ej = e.second.second;
    int ma = (l[ei][ej] + r[ei][ej]) / 2, ms = 0;
    for (int k = r[ei][ej]; k >= l[ei][ej]; k--) {
      a[ei][ej] = k;
      int st = 0;
      for (int i = 0, s = 0; ei + i < n && a[ei + i][ej] != 0; i++) {
        s += a[ei + i][ej];
        for (auto be : b) {
          if (s == be) st += be;
        }
      }
      for (int i = 0, s = 0; ei - i >= 0 && a[ei - i][ej] != 0; i++) {
        s += a[ei - i][ej];
        for (auto be : b) {
          if (s == be) st += be;
        }
      }
      for (int i = 0, s = 0; ej + i < n && a[ei][ej + i] != 0; i++) {
        s += a[ei][ej + i];
        for (auto be : b) {
          if (s == be) st += be;
        }
      }
      for (int i = 0, s = 0; ej - i >= 0 && a[ei][ej - i] != 0; i++) {
        s += a[ei][ej - i];
        for (auto be : b) {
          if (s == be) st += be;
        }
      }
      if (st > ms) {
        ma = k;
        ms = st;
      }
    }
    a[ei][ej] = ma;
    // score += ms;
  }

  // hill climbing
  auto evaluate_row = [&n, &b, &a](int i) {
    int t = 0;
    vector<int> s(n + 1);
    for (int j = 0; j < n; j++) s[j + 1] = s[j] + a[i][j];
    for (int from = 0; from < n; from++) {
      for (int to = from + 1; to <= n; to++) {
        for (auto e : b) {
          if (s[to] - s[from] == e) t += e;
        }
      }
    }
    return t;
  };
  auto evaluate_column = [&n, &b, &a](int j) {
    int t = 0;
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i][j];
    for (int from = 0; from < n; from++) {
      for (int to = from + 1; to <= n; to++) {
        for (auto e : b) {
          if (s[to] - s[from] == e) t += e;
        }
      }
    }
    return t;
  };
  int iteration = 0;
  int score = 0;
  vector<int> sr(n), sc(n);
  for (int i = 0; i < n; i++) score += sr[i] = evaluate_row(i);
  for (int j = 0; j < n; j++) score += sc[j] = evaluate_column(j);

  while (timer.Elapsed() < TIME_LIMIT - 100) {
    iteration++;
    int i = rand() % n, j = rand() % n;
    int ps = score, pe = a[i][j], psr = sr[i], psc = sc[j];
    if (l[i][j] == r[i][j]) {
      continue;
    } else {
      a[i][j] = l[i][j] + rand() % (r[i][j] - l[i][j]);
    }
    score -= sr[i] + sc[j];
    score += sr[i] = evaluate_row(i);
    score += sc[j] = evaluate_column(j);
    if (score < ps) {
      score = ps;
      a[i][j] = pe;
      sr[i] = psr;
      sc[j] = psc;
    }
  }

  // output
  for (const auto& ev : a) {
    for (const auto& e : ev) cout << e << ' ';
    cout << endl;
  }
  cerr << "iteration: " << iteration << endl;
  cerr << "score: " << score << endl;
}
