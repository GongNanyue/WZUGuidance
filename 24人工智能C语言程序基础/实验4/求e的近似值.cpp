#include<stdio.h>
#include<math.h>
double jc(int k);

int main()
{    
	int a;
	double e=0;
	scanf("%d",&a);
	for(int i=0;i<=a;i++){
		e+=1.0/jc(i);
	}
	printf("%.8lf",e);
}

double jc(int k){
	double re=1;
	for(int i=1;i<=k;i++){
		re*=i;
	}
	return re;
}
