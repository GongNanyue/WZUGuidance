#include <bits/stdc++.h>

using namespace std;
int a[255];
int main() {


  char c;
  while ((c = getchar()) && c != '\n') {
    a[c]++;
  }
  while ((c = getchar()) && c != '\n') {
    a[c]++;
  }

  for (int i = 0; i < 127; ++i) {
    while (a[i]) {
      putchar(i);
      a[i]--;
    }
  }
  printf("\n");
  return 0;
}
