#include <stdio.h>
#include<math.h>
int main(){
	float a=0,b=0,c=0;
	float x=0;
	scanf("%f%f%f",&a,&b,&c);
	x=a*powf(1+c,b);
	printf("interest = %.2f",x-a);
}
