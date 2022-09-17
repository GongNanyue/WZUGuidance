#include <bits/stdc++.h>

using namespace std;
int a[100][100];
void init() {
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      a[i][j] = 0;
    }
  }
}
int main() {
  int m;
  scanf("%d", &m);
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    init();
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i < y; ++i) {
      for (int j = 0; j < x; ++j) {
        printf("%d ",a[j][i]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
