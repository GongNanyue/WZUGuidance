#include<stdio.h>
#include<math.h>
int main()
{    
	double e=0,a=1;
	double sum=0;
	scanf("%lf",&e);
	int k=1;
    for(double i=1;fabs(a)>e;i++){
    	a=k/(3*i-2);
    	sum+=a;
    	k*=-1;
	}
	if(e>=1){
		sum=1;
	}
    printf("sum = %.6lf",sum);
}
