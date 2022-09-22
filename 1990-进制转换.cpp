#include <bits/stdc++.h>

using namespace std;
string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  int n, r;
  while (scanf("%d %d", &n, &r)!=EOF) {
    string result = "";
    if(n==0){
      printf("0\n");
      continue;
    }
    if(n<0){
      printf("-");
      n = -n;
    }
    while (n) {
      result = alphabet[n%r] + result;
      n = n/r;
    }
    cout << result << endl;
  }
  return 0;
}
