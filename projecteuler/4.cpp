#include <bits/stdc++.h>
using namespace std;

int main() {
  int answer = 0;
  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      int a = i * j;
      string s = to_string(a);
      bool is_palindrome = true;
      for (int k = 0; k < s.size() / 2; k++) is_palindrome = is_palindrome && s[k] == s[(int)s.size() - 1 - k];
      if (is_palindrome && a > answer) answer = a;
    }
  }
  cout << answer << endl;
}
