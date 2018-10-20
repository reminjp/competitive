#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	if (s == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1 << endl;
	} else {
		vector<bool> u(int(26));
		for (auto e : s) {
			u[e - 'a'] = true;
		}
		if (s.size() == 26) {
			for (bool b = true; b;) {
				for (int i = s.back() - 'a'; i < 26; i++) {
					if (!u[i]) {
						s.pop_back();
						s.push_back('a' + i);
						b = false;
						break;
					}
				}
				if (b) {
					u[s.back() - 'a'] = false;
					s.pop_back();
				}
			}
		} else {
			for (int i = 0; i < 26; i++) {
				if (!u[i]) {
					s.push_back('a' + i);
					break;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
