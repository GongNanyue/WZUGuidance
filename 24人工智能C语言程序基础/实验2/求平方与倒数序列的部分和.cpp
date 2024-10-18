#include <stdio.h>
#include<math.h>
int main(){
	int a=0,b=0;
	double sum=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		sum+=i*i;
		sum+=1.0/i;
	}
	printf("sum = %.6f",sum);
}
