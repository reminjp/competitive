#include <bits/stdc++.h>
using namespace std;

char a[0xff][0xff];

char check(string s) {
	char c = '0';
	for (char& d : s) {
		c = a[c][d];
	}
	return c;
}

int main() {
	for (char i = '0'; i <= '9'; i++) {
		for (char j = '0'; j <= '9'; j++) {
			int k;
			cin >> k;
			a[i][j] = '0' + k;
		}
	}
	int m = 10000;
	for (int n = 0; n < 10000; n++) {
		string s = to_string(10000 + n).substr(1);
		s.push_back(check(s));
		bool ok = true;
		for (int i = 0; i < s.size() && ok; i++) {
			for (char j = '0'; j <= '9' && ok; j++) {
				if (s[i] != j) {
					string t = s;
					t[i] = j;
					if (check(t) == '0') {
						ok = false;
					}
				}
			}
		}
		for (int i = 0; i < s.size() - 1 && ok; i++) {
			if (s[i] != s[i + 1]) {
				string t = s;
				char c = t[i];
				t[i] = t[i + 1];
				t[i + 1] = c;
				if (check(t) == '0') {
					ok = false;
				}
			}
		}
		if (ok) {
			m--;
		}
	}
	cout << m << endl;
	return 0;
}
