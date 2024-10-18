#include<stdio.h>
#include<math.h>
int main(){
	int a;
	scanf("%d",&a);
	double sum=0;
	int k=1;
	for(double i=1;i<=a;i++){
		sum+=i/(i*2-1)*k;
		k*=-1;
	}
	printf("%.3lf",sum);
}
