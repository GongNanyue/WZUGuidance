#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
	float a,b,c,d,x1,x2;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if(d<0){
		cout<<"no"<<endl;
	}
	if(d>0){
		x1=(-1*b+sqrt(d))/(2*a);
		x2=(-1*b-sqrt(d))/(2*a);
		if(x1>x2) printf("%.2f %.2f\n", x1,x2);
		else printf("%.2f %.2f\n", x2,x1);
	}
	if(d==0){
		x1=(-1*b+sqrt(d))/(2*a);
		printf("%.2f\n", x1);
	}
	return 0;
}