// 2016-11-30
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	string u[256], t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> u[i];
	}
	cin >> m;
	bool o = false;
	for (int i = 0; i < m; i++) {
		cin >> t;
		int j;
		for (j = 0; j < n; j++) {
			if (t == u[j]) {
				cout << (o ? "Closed by " : "Opened by ") << t << endl;
				o ^= true;
				break;
			}
		}
		if (j == n) {
			cout << "Unknown " << t << endl;
		}
	}
	return 0;
}
