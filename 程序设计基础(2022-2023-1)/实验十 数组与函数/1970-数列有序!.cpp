#include <bits/stdc++.h>

using namespace std;
int num[100];
int main() {
  int n, m;
  int val;
  while ((scanf("%d %d", &n, &m)) && (n != 0) && (m != 0)) {
    for (int i = 0; i < n ; ++i) {
      scanf("%d", &num[i]);
    }
    int idx = n - 1;
    while (num[idx] > m) {
      num[idx+1]=num[idx];
      --idx;
    }
    num[idx+1]=m;
    for (int i = 0; i < n + 1; ++i) {
      printf("%d", num[i]);
      if(i != n)printf(" ");
    }
    printf("\n");
  }
  return 0;
}
