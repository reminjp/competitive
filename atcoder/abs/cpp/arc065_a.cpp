#include <iostream>
#include <regex>
using namespace std;

int main() {
  string s;
  cin >> s;
  regex r(R"(^(dream|dreamer|erase|eraser)*$)");
  cout << (regex_match(s, r) ? "YES" : "NO") << endl;
  return 0;
}
