#include<stdio.h>
#include<math.h>
double jc(double k);

int main()
{    
	double a;
	double e=0;
	scanf("%lf",&a);
	for(double i=0;powf(a,i-1)/jc(i-1)>=0.00001;i++){
		e+=powf(a,i)/jc(i);
	}
	printf("%.4lf",e);
}

double jc(double k){
	double re=1;
	for(double i=1;i<=k;i++){
		re*=i;
	}
	return re;
}
