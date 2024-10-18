#include <stdio.h>
#include<math.h>
int main(){
	int a=0;
	scanf("%d",&a);
	for(int i=0;i<=a;i++){
		printf("pow(3,%d) = %.0f\n",i,powf(3,i));
	}
}
