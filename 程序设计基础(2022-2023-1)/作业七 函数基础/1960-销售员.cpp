#include <iostream>
#include <stdio.h>
using namespace std;

double hanserSoCuteTakeMyMoneyPlz(int amount){
  if(amount <= 10000) return 0.05*amount;
  else if(amount <= 50000) return 0.075*amount;
  else if(amount <= 200000) return 0.085*amount;
  else return 0.1*amount;
}

int main(){
  int n,i,a;
  cin>>n;
  for(i=1;i<=n;i++){
    cin>>a;
    printf("%.3f\n", 1000+hanserSoCuteTakeMyMoneyPlz(a));
  }
  return 0;
}
