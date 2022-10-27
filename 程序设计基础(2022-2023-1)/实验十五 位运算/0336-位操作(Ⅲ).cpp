#include <bits/stdc++.h>

using namespace std;

int getbits(int x, int p, int n) {
  return (x>>(p-n+1))%2;
}

int main() {
  int x, p, n;
  while((scanf("%d%d%d", &x, &p, &n) != EOF)){
    int sum = 0;
    for(int i = 1; i <= n ;++ i){
      sum = sum *2+getbits(x,p,i);
    }
    cout << sum <<endl;



  }
  return 0;
}
