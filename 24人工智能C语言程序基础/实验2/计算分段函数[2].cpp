#include <stdio.h>
#include<math.h>
int main(){
	float a=0;
	float x=0;
	scanf("%f",&a);
	if(a>=0){
		x=powf(a,0.5);
	}else{
		x=powf(a+1,2)+2*a+1/a;
	}
	printf("f(%.2f) = %.2f",a,x);
}
