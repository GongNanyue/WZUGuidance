#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,m,i,j,t;
	float sum;
	cin>>n;
	for(i=0;i<n;i++){
		sum=0;
		cin>>m;
		for(j=0;j<m;j++){		
			cin>>t;	
			sum+=t;
		}
		printf("%.2f\n", sum/m); 
	}
	return 0;
}
