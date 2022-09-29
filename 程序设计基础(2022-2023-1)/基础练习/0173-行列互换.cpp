#include <bits/stdc++.h>
using namespace std;

int Matrix[110][110];
void init() {
  for (int i = 0; i < 110; ++i) {
    for (int j = 0; j < 110; ++j) {
      Matrix[i][j] = 0;
    }
  }
}
int main() {
  int m;
  scanf("%d", &m);
  while (m--) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        scanf("%d", &Matrix[i][j]);
      }
    }
    for (int row = 0; row < c; ++row) {
      for (int column= 0; column < r; ++column) {
        printf("%d ",Matrix[column][row]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}




