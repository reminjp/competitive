#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> q = {2, 3, 5, 7};
	int n = 1;
	for (auto e : q) {
		cout << "Q " << e;
		int a;
		cin >> a;
		n *= pow(e, a);
	}
	cout << "A " << n << endl;
	return 0;
}
