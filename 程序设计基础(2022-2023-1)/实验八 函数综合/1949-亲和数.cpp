#include <bits/stdc++.h>
using namespace std;
int factorSum(int a) {
  int sum = 0;
  for (int i = 1; i < a; ++i) {
    if (a % i == 0)sum += i;
  }
  return sum;
}

bool isRelative(int a, int b) {
  return (factorSum(a) == b) || (factorSum(b) == a);
}
int main() {
  int m;
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (isRelative(a, b))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
