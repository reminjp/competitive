#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  vector<int> a(n), v(n);
  int is = -1, id = -1, vs, vd;
  for (int q = 0; q < 150;) {
    if (q % 10 == 0 && (is != -1 || id != -1)) {
      bool fliped = false, reversed = false;

      int rs, rd;
      if (is != -1 && id != -1) {
        q += 2;
        cout << is + 1 << endl;
        cin >> rs;
        cout << id + 1 << endl;
        cin >> rd;
        fliped = rs != vs;
        reversed = fliped ? rd == vd : rd != vd;
      } else if (is != -1) {
        q++;
        cout << is + 1 << endl;
        cin >> rs;
        fliped = rs != vs;
      } else if (id != -1) {
        q++;
        cout << id + 1 << endl;
        cin >> rd;
        reversed = rd != vd;
      }

      if (fliped) {
        for (auto &e : a) e = !e;
        vs = !vs;
        vd = !vd;
      }
      if (reversed) {
        reverse(a.begin(), a.end());
        reverse(v.begin(), v.end());
        vd = !vd;
      }
    } else {
      int r;
      for (int i = 0; i < (n + 1) / 2; i++) {
        if (v[i] && v[n - 1 - i]) continue;

        if (!v[i]) {
          q++;
          cout << i + 1 << endl;
          cin >> r;
          a[i] = r;
          v[i] = true;
        } else if (!v[n - 1 - i]) {
          q++;
          cout << (n - 1 - i) + 1 << endl;
          cin >> r;
          a[n - 1 - i] = r;
          v[n - 1 - i] = true;
        }

        if (v[i] && v[n - 1 - i]) {
          if (a[i] == a[n - 1 - i]) {
            is = i;
            vs = a[i];
          } else {
            id = i;
            vd = a[i];
          }

          if (i == (n + 1) / 2 - 1) {
            for (auto e : a) cout << e;
            cout << endl;
            string response;
            cin >> response;
            if (response == "N") exit(0);
            return;
          }
        }

        break;
      }
    }
  }
}

int main() {
  int t, b;
  cin >> t >> b;
  while (t--) solve(b);
}
