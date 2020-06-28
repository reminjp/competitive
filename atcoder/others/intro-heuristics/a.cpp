#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  srand(0);

  // input
  constexpr int n = 26;
  int d;
  cin >> d;
  vector<int> c(n);
  for (auto &e : c) cin >> e;
  vector<vector<int>> s(d, vector<int>(n));
  for (auto &se : s) {
    for (auto &e : se) cin >> e;
  }

  // solve
  int satisfaction = 0;
  vector<set<int>> v(n);
  for (auto &e : v) e.insert(-1);
  vector<int> t(d);
  for (int i = 0; i < d; i++) {
    t[i] = max_element(s[i].begin(), s[i].end()) - s[i].begin();
    satisfaction += s[i][t[i]];
    v[t[i]].insert(i);

    for (int j = 0; j < n; j++) {
      int last_i = *v[j].rbegin();
      satisfaction -= c[j] * (i - last_i);
    }
  }

  auto calculate_decline = [](int c, int d) { return -c * ((d - 1) * d / 2); };

  auto calculate_difference = [&](int i, int j) {
    int difference = 0;
    difference -= s[i][t[i]];
    difference += s[i][j];

    auto it1_to = v[t[i]].upper_bound(i);
    auto it1_from = it1_to;
    it1_from--;
    it1_from--;
    int i1_to = it1_to == v[t[i]].end() ? d : *it1_to, i1_from = *it1_from;

    auto it2_to = v[j].upper_bound(i);
    auto it2_from = it2_to;
    it2_from--;
    int i2_to = it2_to == v[j].end() ? d : *it2_to, i2_from = *it2_from;

    difference -= calculate_decline(c[t[i]], i - i1_from) + calculate_decline(c[t[i]], i1_to - i);
    difference += calculate_decline(c[t[i]], i1_to - i1_from);

    difference -= calculate_decline(c[j], i2_to - i2_from);
    difference += calculate_decline(c[j], i - i2_from) + calculate_decline(c[j], i2_to - i);

    return difference;
  };

  auto calculate_difference_swap = [&](int i) {
    int difference = 0;
    difference -= s[i][t[i]];
    difference += s[i][t[i + 1]];
    difference -= s[i + 1][t[i + 1]];
    difference += s[i + 1][t[i]];

    auto it1_to = v[t[i]].upper_bound(i);
    auto it1_from = it1_to;
    it1_from--;
    it1_from--;
    int i1_to = it1_to == v[t[i]].end() ? d : *it1_to, i1_from = *it1_from;

    auto it2_to = v[t[i + 1]].upper_bound(i + 1);
    auto it2_from = it2_to;
    it2_from--;
    it2_from--;
    int i2_to = it2_to == v[t[i + 1]].end() ? d : *it2_to, i2_from = *it2_from;

    difference -= calculate_decline(c[t[i]], i - i1_from) + calculate_decline(c[t[i]], i1_to - i);
    difference += calculate_decline(c[t[i]], (i + 1) - i1_from) + calculate_decline(c[t[i]], i1_to - (i + 1));

    difference -= calculate_decline(c[t[i + 1]], (i + 1) - i2_from) + calculate_decline(c[t[i + 1]], i2_to - (i + 1));
    difference += calculate_decline(c[t[i + 1]], i - i2_from) + calculate_decline(c[t[i + 1]], i2_to - i);

    return difference;
  };

  double temperature_from = 1e4, temperature_to = 0;

  for (int iteration = 0, iteration_end = 9e6; iteration < iteration_end; iteration++) {
    double temperature = temperature_from + (temperature_to - temperature_from) * iteration / iteration_end;

    if (rand() % 2) {
      int i = rand() % d, j = rand() % n;
      if (t[i] == j) continue;

      int difference = 0;
      difference += calculate_difference(i, j);

      double probability = exp(difference / temperature);

      if ((rand() % INF) / (double)INF < probability) {
        satisfaction += difference;
        v[t[i]].erase(i);
        v[j].insert(i);
        t[i] = j;
      }
    } else {
      int i = rand() % (d - 1);
      if (t[i] == t[i + 1]) continue;

      int difference = 0;
      difference += calculate_difference_swap(i);

      double probability = exp(difference / temperature);

      if ((rand() % INF) / (double)INF < probability) {
        satisfaction += difference;
        v[t[i]].erase(i);
        v[t[i]].insert(i + 1);
        v[t[i + 1]].erase(i + 1);
        v[t[i + 1]].insert(i);
        swap(t[i], t[i + 1]);
      }
    }
  }

  // output
  cerr << "satisfaction: " << satisfaction << endl;
  cerr << "score: " << max((int)1e6 + satisfaction, 0) << endl;

  for (auto e : t) cout << e + 1 << endl;
}
