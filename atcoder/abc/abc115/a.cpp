#include <bits/stdc++.h>
using namespace std;

int main() {
  int d;
  cin >> d;
  string r = "Christmas";
  for (int i = 25; i > d; i--) r += " Eve";
  cout << r << endl;
}
