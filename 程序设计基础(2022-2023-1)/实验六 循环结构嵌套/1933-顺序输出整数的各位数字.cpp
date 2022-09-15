#include <iostream>
#include <string>
using namespace std;
int main(){
  int n,i,j;
  cin>>n;
  string s[233];
  for(i=0;i<n;i++)
    cin>>s[i];
  for(i=0;i<n;i++){
    for(j=0;j<s[i].length();j++){
      cout<<s[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}