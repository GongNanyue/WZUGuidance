#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int i,n;float sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
		sum+=(1.0/i);
	printf("%.3f\n", sum);
	return 0; 
}