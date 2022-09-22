#include <iostream>
#include <stdio.h>
using namespace std;

bool divide7(int n){
  if(n%7==0)
    return true;
  else
    return false;
}

bool contain7(int n) {
    if (n == 0) return false;
    if (n % 10 == 7) return true;
    return contain7(n / 10);
}

int main()
{
  int n,i,s;
  s=0;
  cin>>n;
  for(i=1;i<=n;i++){
    if(!divide7(i)&&!contain7(i))
      s+=i*i;
  }
  cout<<s<<endl;
  return 0;
}
