#include <bits/stdc++.h>
using namespace std;

const int TIME_LIMIT = 2000;

class timer {
 public:
  timer() : time_begin(clock()) {}
  int elapsed() { return (int)1000 * (clock() - time_begin) / CLOCKS_PER_SEC; }

 private:
  clock_t time_begin;
};

using vector2 = complex<double>;

double variance(const vector<int> &route, const vector<vector<double>> &distances) {
  int n = route.size();
  double v = 0, a = 0;
  for (int i = 0; i < n; i++) {
    a += distances[route[i]][route[(i + 1) % n]];
  }
  a /= n;
  for (int i = 0; i < n; i++) {
    v += pow(distances[route[i]][route[(i + 1) % n]] - a, 2);
  }
  v /= n;
  return v;
}

double score(double variance) { return 1e6 / variance; }

int main() {
  timer t;
  srand(0);

  int n;
  cin >> n;
  vector<vector2> points(n);
  for (auto &e : points) {
    int x, y;
    cin >> x >> y;
    e = vector2(x, y);
  }

  vector<vector<double>> distances(n, vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distances[i][j] = abs(points[j] - points[i]);
    }
  }

  vector<int> current_route(n), best_route(n), next_route(n);
  iota(begin(current_route), end(current_route), 0);
  best_route = current_route;
  double current_score = score(variance(current_route, distances));
  double best_score = current_score;

  while (t.elapsed() < TIME_LIMIT - 20) {
    next_route = current_route;
    int p = rand() % n;
    int q = (q + 1 + rand() % (n - 1)) % n;
    swap(next_route[p], next_route[q]);
    double next_score = score(variance(next_route, distances));

    if (next_score > best_score) {
      best_route = current_route = next_route;
      best_score = current_score = next_score;
      continue;
    }

    double temperature = pow(0.5, double(t.elapsed()) / TIME_LIMIT);
    double probability = next_score >= current_score ? 1.0 : exp(double(next_score - current_score) / temperature);
    if ((double)rand() / RAND_MAX < probability) {
      current_route = next_route;
      current_score = next_score;
    }
  }

  for (auto e : best_route) {
    cout << e << endl;
  }
  cerr << fixed << setprecision(6);
  cerr << "score: " << best_score << endl;
  cerr << "time: " << t.elapsed() << endl;
}
