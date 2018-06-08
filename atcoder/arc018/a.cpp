#include <bits/stdc++.h>
using namespace std;

int main() {
  float height, bmi;
  cin >> height >> bmi;
  height /= 100;
  cout << fixed << setprecision(2) << bmi * height * height << endl;
}
