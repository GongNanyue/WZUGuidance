#include <bits/stdc++.h>

using namespace std;
string s1,s2;
void init() {
  s1.clear();
  s2.clear();
}
ptrdiff_t mycmp(string str1, string str2) {
  ptrdiff_t delta = 0;
  while (str1[delta]==str2[delta])++delta;
  return delta;
}

int main() {
  int m;
  scanf("%d", &m);
  init();
  getchar();
  getline(cin,s1);

  getline(cin,s2);
  ptrdiff_t diffv = mycmp(s1, s2);
  printf("%d\n", s1[diffv] - s2[diffv]);
  m = m-1;
  while (m--) {
    init();
    getchar();
    getline(cin,s1);
    getchar();
    getline(cin,s2);

    ptrdiff_t diffv = mycmp(s1, s2);
    printf("%d\n", s1[diffv] - s2[diffv]);
  }

  return 0;
}
