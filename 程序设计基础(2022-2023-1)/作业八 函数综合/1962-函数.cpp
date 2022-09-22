#include <iostream>
#include <stdio.h>
using namespace std;

int total(int n){
  int i=1;
  int sum=0;
  while(i<=n){
    sum+=i;
    i++;
  }
  return sum;
}

int main()
{
  int n;
  double sum=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    sum+=1.0/total(i);
  }
  printf("%.3f\n",sum);
  return 0;
}
