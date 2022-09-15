#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	double a;int b,i;
	double sum=1;
	cin>>a>>b; 
	for(int i=1;i<=b;i++)
		sum*=a;
	printf("%.3f\n", sum);
}