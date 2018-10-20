#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> u = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
	vector<int> v = {2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326};
	int a, b;
	cin >> a >> b;
	int w = v.size(), t = (b + 3) / 6;
	for (int i = 0; i < v.size(); i++) {
		if (t <= v[i]) {
			w = i;
			break;
		}
	}
	string d = w ? u[(2 * a + 3600 / u.size()) % 7200 / (7200 / u.size())] : "C";
	cout << d << " " << w << endl;
	return 0;
}
