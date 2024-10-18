#include<stdio.h>
#include<math.h>
int main(){
	double a,b;
	scanf("%lf",&a);
	if(a!=10){
		b=a;
	}else{
		b=1.0/a;
	}
	printf("f(%.1lf) = %.1lf",a,b);
}
