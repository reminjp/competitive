// 2017-02-21
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (; n > 0; n--) {
		string s, t;
		list<char> l;
		cin >> s >> t;
		for (int i = 0; i < t.length(); i++) {
			l.push_back(t[i]);
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == 'J') {
				char c = l.back();
				l.pop_back();
				l.push_front(c);
			} else if (s[i] == 'C') {
				char c = l.front();
				l.pop_front();
				l.push_back(c);
			} else if (s[i] == 'E') {
				list<char> m;
				int a = l.size();
				while (l.size() > a / 2) {
					char c = l.front();
					l.pop_front();
					m.push_back(c);
				}
				if (a % 2 != 0) {
					char c = m.back();
					m.pop_back();
					l.push_back(c);
				}
				while (!m.empty()) {
					char c = m.front();
					m.pop_front();
					l.push_back(c);
				}
			} else if (s[i] == 'A') {
				l.reverse();
			} else if (s[i] == 'P') {
				for (auto it = begin(l); it != end(l); it++) {
					if (*it >= '0' && *it <= '9') {
						*it = (*it - '0' + 9) % 10 + '0';
					}
				}
			} else if (s[i] == 'M') {
				for (auto it = begin(l); it != end(l); it++) {
					if (*it >= '0' && *it <= '9') {
						*it = (*it - '0' + 1) % 10 + '0';
					}
				}
			}
		}
		for (auto it = begin(l); it != end(l); it++) {
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
