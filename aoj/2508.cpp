// 2017-02-21
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int k[100];
		string s;
		for (int i = 0; i < n; i++) {
			cin >> k[i];
		}
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			char d;
			if (s[i] >= 'A' && s[i] <= 'Z') {
				d = s[i] - 'A';
			} else {
				d = s[i] - 'a' + 26;
			}
			d = (52 + d - k[i % n]) % 52;
			if (d < 26) {
				s[i] = d + 'A';
			} else {
				s[i] = d + 'a' - 26;
			}
		}
		cout << s << endl;
	}
	return 0;
}
