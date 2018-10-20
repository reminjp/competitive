#include <bits/stdc++.h>
using namespace std;

int main() {
	int y;
	cin >> y;
	bool r;
	if (y % 400 == 0) {
		r = true;
	} else if (y % 100 == 0) {
		r = false;
	} else if (y % 4 == 0) {
		r = true;
	} else {
		r = false;
	}
	cout << (r ? "YES" : "NO") << endl;
	return 0;
}
