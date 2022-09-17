#include <bits/stdc++.h>

using namespace std;
int a[100];
int main() {
  int m;
  scanf("%d", &m);
  a[1] = 1;
  a[2] = 1;
  int idxmax = 2;
  while (m--) {
    int n;
    scanf("%d", &n);
    if (a[n]) {
      printf("%d\n", a[n]);
      continue;
    }
    for (int i = idxmax; i <= n; ++i) {
      a[i] = a[i-1]+a[i-2];
    }
    printf("%d\n",a[n]);
    idxmax = n;
  }
  return 0;
}
