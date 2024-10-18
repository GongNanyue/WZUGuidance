#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c,d,sum;
	double av;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	sum=a+b+c+d;
	av=sum/4.0;
	printf("Sum = %d; Average = %.1lf",sum,av);
}
