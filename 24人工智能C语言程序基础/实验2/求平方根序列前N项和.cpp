#include <stdio.h>
#include<math.h>
int main(){
	long long a=0;
	scanf("%d",&a);
	double sum=0;
	for(int i=1;i<=a;i++){
		sum+=sqrt(i);
	}
	printf("sum = %.2f",sum);
}
