// 2017-02-03
#include <iostream>
using namespace std;

int main() {
	int n;
	int a[100001 + 1] = {};
	int b[100001 + 1] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x]++; b[y]++;
	}
	int p = 1;
	int r = 1;
	for (int i = 2; i <= 100001; i++) {
		p = p + a[i] - b[i - 1];
		if (i <= p) r = i;
	}
	cout << r - 1 << endl;
	return 0;
}
