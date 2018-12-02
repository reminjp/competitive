// 2017-03-13
#include <iostream>
#include <string>
using namespace std;

int gcd(int m, int n) {
	while (n != 0) {
		int t = n;
		n = m % n;
		m = t;
	}
	return m;
}

int main() {
	string s;
	while (cin >> s, s != "#") {
		int n = 0;
		bool d[20];
		for (int i = 0; i < s.length(); ) {
			if (s[i] == 'n') {
				d[n] = false; // north
				i += 5;
			} else {
				d[n] = true; // west
				i += 4;
			}
			n++;
		}
		int a = d[n - 1] ? 90 : 0;
		int b = 1;
		for (int i = n - 2; i >= 0; i--) {
			a = 2 * a + (d[i] ? 90 : -90);
			b *= 2;
		}
		int c = gcd(a, b);
		if (b == c) {
			cout << a / c << endl;
		} else {
			cout << a / c << "/" << b / c << endl;
		}
	}
	return 0;
}
