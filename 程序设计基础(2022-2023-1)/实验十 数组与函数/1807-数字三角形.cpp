#include <bits/stdc++.h>

using namespace std;
int tri[30][30];
void init() {
  for (int i = 0; i < 30; ++i) {
    for (int j = 0; j < 30; ++j) {
      tri[i][j] = 0;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int cnt;
    scanf("%d", &cnt);
    init();
    int idx = 1;

    for (int i = 0; i < cnt; ++i) {
      for (int j = 0; j < cnt - i; ++j) {
        tri[i][j] = idx++;
      }
    }
    for (int i = 0; i < cnt; ++i) {
      for (int j = 0; j < cnt - i; ++j) {
        printf("%d ",tri[j][i]);
      }
      printf("\n");
    }
  }

  return 0;
}
