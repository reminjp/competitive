// 2017-02-28
#include <iostream>
#include <string>
using namespace std;

int main() {
	const int n = 13;
	string s;
	int l;
	getline(cin, s);
	l = s.length();
	for (int i = 0; i < l; i++) {
		char c = s[i];
		if (c >= 'A' && c <= 'Z') {
			c = (c - 'A' + n) % 26 + 'A';
		} else if (c >= 'a' && c <= 'z') {
			c = (c - 'a' + n) % 26 + 'a';
		}
		s[i] = c;
	}
	cout << s << endl;
	return 0;
}
