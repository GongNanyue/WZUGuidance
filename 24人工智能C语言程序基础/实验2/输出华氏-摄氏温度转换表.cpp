#include <stdio.h>
#include<math.h>
int main(){
	int a=0,b=0;
	scanf("%d%d",&a,&b);
	if(a>b || b>100){
		printf("Invalid.");
		return 0;
	}
	printf("fahr celsius\n");
	for(int i=a;i<=b;i+=2){
		printf("%d",i);
		printf("%6.1f\n",5.0*(i-32.0)/9);
	}
}
