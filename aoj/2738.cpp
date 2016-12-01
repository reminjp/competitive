// 2016-12-02
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int c = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == 'A') {
			c++;
		} else {
			c--;
			if (c < 0) {
				break;
			}
		}
	}
	if (c) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
	return 0;
}
