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

int main() {
  int n;
  scanf("%d", &n);
  if (is_leapYear(n)) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
  return 0;

}
