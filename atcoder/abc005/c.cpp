#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	queue<int> a, b;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		a.push(e);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int e;
		cin >> e;
		b.push(e);
	}
	while (!a.empty() && !b.empty()) {
		if (b.front() < a.front()) {
			break;
		} else if (b.front() <= a.front() + t) {
			b.pop();
		}
		a.pop();
	}
	cout << (b.empty() ? "yes" : "no") << endl;
	return 0;
}
