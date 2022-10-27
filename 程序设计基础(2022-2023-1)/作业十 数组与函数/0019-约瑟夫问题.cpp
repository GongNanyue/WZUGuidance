#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, m, idx = 0;
  while (scanf("%d %d", &n, &m) && n && m) {
    idx = 0;
    bool visit[1000] = {false};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (++idx > n)idx = 1;
        if (visit[idx])--j;
      }
      if (i == n - 1)printf("%d\n", idx);
      visit[idx] = true;
    }
  }
  return 0;
}


