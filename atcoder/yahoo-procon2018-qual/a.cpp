#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << (s.size() == 5 && s.substr(0, 3) == "yah" && s[3] == s[4] ? "YES" : "NO") << endl;
	return 0;
}
