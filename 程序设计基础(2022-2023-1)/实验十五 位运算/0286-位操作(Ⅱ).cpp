#include <bits/stdc++.h>

using namespace std;

bool is(unsigned short a, unsigned short b) {
  if(a == b)return true;
  for(int i = 0; i<15; ++i){
    a = (a<<1)+(a/32768);
    if(a == b)return true;
  }
  return false;




}

int main() {
  int n;
  cin>>n;
  while(n--){
    unsigned short a, b;
    cin>>a>>b;
    if(is(a, b)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
