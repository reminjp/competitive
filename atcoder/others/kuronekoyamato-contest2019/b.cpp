#include <bits/stdc++.h>
using namespace std;

constexpr double VEHICLE_SPEED = 250;
constexpr double CART_SPEED = 100;

struct Park {
  string id;
  double ton, toff;
};

struct Destination {
  string id;
  double tstay;
  int r;
};

int main() {
  int k, l;
  cin >> k >> l;
  vector<Park> parks(k);
  for (auto& e : parks) cin >> e.id >> e.ton >> e.toff;
  vector<Destination> destinations(l);
  for (auto& e : destinations) cin >> e.id >> e.tstay >> e.r;
  vector<vector<double>> a(k + l, vector<double>(k + l));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
      a[i][j] /= VEHICLE_SPEED;
    }
  }
  for (int i = k; i < k + l; i++) {
    for (int j = 0; j < k + l; j++) {
      cin >> a[i][j];
      a[i][j] /= CART_SPEED;
      if (j < k) a[j][i] = a[i][j];
    }
  }

  vector<int> nearestPark(l);
  vector<vector<int>> nearDestinations(k);
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < k; j++) {
      if (a[k + i][j] < a[k + i][nearestPark[i]]) {
        nearestPark[i] = j;
      }
    }
    if (destinations[i].r != 0) nearDestinations[nearestPark[i]].push_back(i);
  }

  for (int i = 0; i < k; i++) {
    if (nearDestinations[i].size() == 0) continue;
    cout << parks[i].id << ' ';
    for (auto j : nearDestinations[i]) {
      cout << destinations[j].id << ' ';
    }
    cout << endl;
  }
}
