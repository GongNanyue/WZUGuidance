#include <bits/stdc++.h>

using namespace std;
bool isTriangle(int a, int b, int c) {
  if (a  + b  > c  || a + c > b  || b + c  > a ) {
    return true;
  } else {
    return false;
  }
}
bool isRightAngle(int c, int a, int b) {
  return (c * c == b * b + a * a);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; ++kase) {
    int val;
    scanf("%d", &val);
    int sum = 0;
    for (int i = 3; i < val; ++i) {
      for (int j = i + 1; j < val; ++j) {
        for (int k = j + 1; k <= val; ++k) {
          if (isTriangle(k, i, j)&& isRightAngle(k,i,j))sum++;
        }
      }
    }
    printf("case#%d\n", kase);
    printf("%d\n", sum);
  }
  return 0;
}
