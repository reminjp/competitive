#include <bits/stdc++.h>
using namespace std;

constexpr double PI = 3.141593;

constexpr int Xs = 0, Ys = 470;
constexpr int Xa = 0, Ya = 900;
constexpr int Xb = 900, Yb = 0;
constexpr int Xc = 900, Yc = 900;
constexpr int Xe = 90, Ye = 50;

constexpr int CAPACITY = 120'000;
constexpr int MAX_SPEED = 500;
constexpr int MIN_ACCELERATION_TIME = 60;
constexpr int MAX_ACCELERATION_TIME = 3000;

int main() {
  int La, Lb, Lc, Na, Nb, Nc, Ne, Ma, Mb, Mc, Tc;
  cin >> La >> Lb >> Lc >> Na >> Nb >> Nc >> Ne >> Ma >> Mb >> Mc >> Tc;

  int x = Xs, y = Ys, ta = 0;
  for (int line = 0; line < 2; line++) {
    int X, Sx, Ax, Dx, Y, Sy, Ay, Dy, Ta, Wa, Wb, Wc, We;
    Sx = Sy = MAX_SPEED;
    Ax = Ay = Dx = Dy = MIN_ACCELERATION_TIME;
    Ta = ta;
    Wa = Wb = Wc = We = 0;

    if (line == 0) {
      X = Xa + La * cos(ta / 180.0 * PI);
      Y = Ya - La * sin(ta / 180.0 * PI);
      Wa = min(Ma, CAPACITY / Na);
    } else {
      X = Xe;
      Y = Ye;
      We = 60000;
    }

    x = X;
    y = Y;
    ta = Ta;
    cout << X << ',';
    cout << Sx << ',';
    cout << Ax << ',';
    cout << Dx << ',';
    cout << Y << ',';
    cout << Sy << ',';
    cout << Ay << ',';
    cout << Dy << ',';
    cout << Ta << ',';
    cout << Wa << ',';
    cout << Wb << ',';
    cout << Wc << ',';
    cout << We << endl;
  }
}
