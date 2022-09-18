#include <bits/stdc++.h>

using namespace std;
int fabo[1000];
void getvalue(int idxmax, int n) {
  for (int i = idxmax + 1; i < n + 1; ++i) {
    fabo[i] = fabo[i - 1] + fabo[i - 2];
  }
}
int main() {
  fabo[0] = 0;
  fabo[1] = 1;
  int n;
  int idxmax = 1;
  while ((cin >> n) && n != -1) {
    if (n > idxmax)
      getvalue(idxmax, n);
    printf("%d\n", fabo[n]);
  }
  return 0;
}
