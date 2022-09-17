#include <bits/stdc++.h>

using namespace std;
string int_to_binary(int x) {
  string str;
  while (x) {
    str.push_back((x % 2) + '0');
    x /=2;
  }
  std::reverse(str.begin(), str.end());
  return str;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    string str = int_to_binary(n);
    printf("%s\n", str.c_str());
  }

  return 0;
}
