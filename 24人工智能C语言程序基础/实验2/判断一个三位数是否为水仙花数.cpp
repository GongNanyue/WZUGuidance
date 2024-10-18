#include <stdio.h>
#include<math.h>
int main(){
	int x=0;
	scanf("%d",&x);
	int a=0,b=0,c=0;
	a=x/100;
	b=x%100/10;
	c=x%10;
	if(x>999||x<100){
		printf("Invalid Value.");
		return 0;
	}
	if(a*a*a+b*b*b+c*c*c==x){
		printf("Yes");
		return 0;
	}
	printf("No");
}
