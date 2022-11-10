#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int ar, ac;
bool check(int r, int c) {
  for (int i = 0; i < ac; ++i) {
    if (a[r][i] > a[r][c])return false;
  }
  for (int i = 0; i < ar; ++i) {
    if (a[i][c] < a[r][c])return false;
  }
  return true;
}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  scanf("%d %d", &ar, &ac);
  for (int i = 0; i < ar; ++i) {
    for (int j = 0; j < ac; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  bool flag = false;
  for (int i = 0; i < ar; ++i) {
    for (int j = 0; j < ac; ++j) {
      if (check(i, j)) {
        printf("%d %d %d \n", i, j, a[i][j]);
        flag = true;
        break;
      }
    }
  }
  if (!flag) {
    printf("N\n");
  }
//  fclose(stdin);
//  fclose(stdout);
  return 0;
}
