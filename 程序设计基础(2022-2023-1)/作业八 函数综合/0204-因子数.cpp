#include <iostream>
#include <stdio.h>
using namespace std;

int getFactorNumber(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main()
{
  int n,i,j,a,b,m,o;
  cin>>n;
  for(i=1;i<=n;i++){
    o=0;m=0;
    cin>>a>>b;
    for(j=b;j>=a;j--){
      if(getFactorNumber(j)>=m){
        m=getFactorNumber(j);
        o=j;
      }
    }
    cout<<o<<endl;
  }
  return 0;
}