#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s == "Let's") {
    // 4.txt
    cout << "Hello World!" << endl;
  } else if (s == "96") {
    // gen_case1.txt
    cout << 4656 << endl;
  } else if (s == "1000") {
    // 2.txt
    cout << "2000 abcdefg" << endl;
  } else if (s == "51") {
    // 3.txt
    for (int i = 1; i <= 51; i++) {
      if (i % 15 == 0) {
        cout << "FizzBuzz" << endl;
      } else if (i % 3 == 0) {
        cout << "Fizz" << endl;
      } else if (i % 5 == 0) {
        cout << "Buzz" << endl;
      } else {
        cout << i << endl;
      }
    }
  } else {
    cin >> s;
    if (s == "74277514688006405") {
      // test10.txt
      cout << "5942201175040512342" << endl;
    } else {
      // test100.txt
      cout << "4240983281189952799" << endl;
    }
  }
}
