#include<stdio.h>
#include<math.h>
int main(){
	int a;
	scanf("%d",&a);
	double sum=0;
	for(int i=1;i<=a;i++){
		sum+=pow(2,i);
	}
	printf("result = %.0lf",sum);
}
