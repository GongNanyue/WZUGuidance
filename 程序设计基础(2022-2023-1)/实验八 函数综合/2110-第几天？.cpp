//警告 这个带代码不能编译通过 使用了vector和列表初始化

#include <bits/stdc++.h>
using namespace std;
bool is_leapYear(int y) {
  if (y % 400 == 0) {
    return true;
  } else if (y % 100 == 0) {
    return false;
  } else if (y % 4 == 0) {
    return true;
  } else {
    return false;
  }
}
char s[20];
vector<int> monthday = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int m;
  scanf("%d", &m);
  while (m--) {
    scanf("%s", s);
    vector<int> v;
    int n = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
      if (s[i] == '/') {
        v.push_back(n);
        n = 0;
      } else {
        n = n * 10 + s[i] - '0';
      }
    }
    v.push_back(n);
    int sum = 0;
    for (int i = 0; i < v[1]-1; ++i) {
      sum += monthday[i];
    }
    if (is_leapYear(v[0]) && v[1] > 2)
      sum += 1;
    sum += v[2];
    printf("%d\n",sum);
  }
  return 0;
}
