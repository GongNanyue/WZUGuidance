#include <bits/stdc++.h>

using namespace std;


int main() {
  unsigned short n;
  while(scanf("%d",&n)!=EOF){
    cout << (n >> 4)%(2*2*2*2)<< endl;
  }
  return 0;
}
