#include <iostream>
using namespace std;

int cow(int n){
  if(n <= 4) return n;
  return cow(n-1) + cow(n-3); // Copilot wrote that, not me
}

int main()
{
  int n;
  while(cin>>n&&n){
    cout<<cow(n)<<endl;
  }
  return 0;
}