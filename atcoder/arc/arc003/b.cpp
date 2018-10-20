#include <bits/stdc++.h>
using namespace std;

string reverse(string s) {
	string t;
	for (auto it = rbegin(s); it != rend(s); it++) {
		t.push_back(*it);
	}
	return t;
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& e : v) {
		cin >> e;
		e = reverse(e);
	}
	sort(begin(v), end(v));
	for (auto& e : v) {
		cout << reverse(e) << endl;
	}
	return 0;
}
