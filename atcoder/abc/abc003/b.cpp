#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	bool r = true;
	for (int i = 0; i < s.size(); i++) {
		char a = min(s[i], t[i]), b = max(s[i], t[i]);
		if (!(a == b || (a == '@' && (b == 'a' || b == 't' || b == 'c' || b == 'o' || b == 'd' || b == 'e' || b == 'r')))) {
			r = false;
			break;
		}
	}
	cout << (r ? "You can win" : "You will lose") << endl;
	return 0;
}
