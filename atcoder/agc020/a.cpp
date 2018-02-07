#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	cout << ((b - a - 1) % 2 ? "Alice" : "Borys") << endl;
	return 0;
}
