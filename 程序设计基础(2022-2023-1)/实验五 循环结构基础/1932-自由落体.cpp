#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	float h,s;int n,i;
	cin>>h>>n;
	if(n==1){
		cout<<"100.000000\n"<<endl;
		return 0;
	}
	s=h;h=h/2;
	for(i=2;i<=n;i++){
		s+=h*2;
		h=h/2; 
	}
	printf("%.6f\n", s);
	return 0; 
}