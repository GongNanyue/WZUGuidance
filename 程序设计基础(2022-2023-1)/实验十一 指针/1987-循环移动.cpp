#include <bits/stdc++.h>

using namespace std;
int a[100];
void myswap(int *p1, int *p2) {
  int t = *p1;
  *p1 = *p2;
  *p2 = t;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int *ip0 = a, *ip1 = a + n ;
  for (; ip0 < a + n-m; ++ip0, ++ip1) {
    myswap(ip0,ip1);
  }
  for(int *it = ip0;it != ip1;++it){
    printf("%d",*it);
    if(it != ip1-1)printf(" ");
  }
  printf("\n");
  return 0;
}
