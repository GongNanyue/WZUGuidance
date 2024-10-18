#include<stdio.h>
#include<math.h>

int main()
{    
	double a=0,b=0,cnt=0;
	double sum=0;
	scanf("%lf%lf",&a,&b);
	sum=-a;
	for(int i=0;i<b;i++){
		sum+=2*a;
		a/=2.0;
	}
	if(b==0){
		sum=0;
		a=0;
	}
	if(a==0){
		
	}
	printf("%.1f %.1f",sum,a);
}

