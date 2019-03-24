#include <bits/stdc++.h>
using namespace std;

int main() {
  map<char, char> m;
  m['A'] = 'T';
  m['T'] = 'A';
  m['G'] = 'C';
  m['C'] = 'G';
  string s;
  cin >> s;
  cout << m[s[0]] << endl;
}
