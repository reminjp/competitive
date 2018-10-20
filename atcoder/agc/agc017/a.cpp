#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	static ll C[51][51];
	for (int i = 0; i <= 50; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	int n, p;
	cin >> n >> p;
	int b[2] = {};
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		b[a % 2]++;
	}
	ll m = 0;
	for (int i = 0; i <= b[0]; i++) {
		for (int j = p; j <= b[1]; j += 2) {
			m += C[b[0]][i] * C[b[1]][j];
		}
	}
	cout << m << endl;
	return 0;
}
