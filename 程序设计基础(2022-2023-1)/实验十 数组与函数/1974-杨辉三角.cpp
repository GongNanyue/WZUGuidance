#include <bits/stdc++.h>

using namespace std;
int a[100][100];

int main() {
  int n;
  int nmax = 1;
  a[1][1] = 1;
  while (scanf("%d", &n) != EOF) {
    // i for row ,j for column
    for (int i = nmax + 1; i <= n; ++i) {
      for (int j = nmax; j <= i; ++j) {
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        printf("%d",a[i][j]);
        if(j != i)printf(" ");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}1974-杨辉三角
