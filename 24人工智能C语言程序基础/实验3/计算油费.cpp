#include <stdio.h>
#include<math.h>
int main(){
	float p[100]={0};
	p[90]=6.95;
	p[93]=7.44;
	p[97]=7.93;
	int a,b;
	char c;
	float z=0.97;
	scanf("%d %d %c",&a,&b,&c);
	if(c=='m'){
		z=0.95;
	}
	double r=a*p[b]*z;
	printf("%.2lf",r);
}
