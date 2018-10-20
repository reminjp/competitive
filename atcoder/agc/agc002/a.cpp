#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string r;
	if (0 < a) {
		r = "Positive";
	} else if (0 <= b) {
		r = "Zero";
	} else {
		r = ((b - a + 1) % 2 ? "Negative" : "Positive");
	}
	cout << r << endl;
	return 0;
}
