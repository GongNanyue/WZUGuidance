#include <stdio.h>
#include<math.h>
int main(){
	int a=0,t=0,y=0,u=0;
	scanf("%d",&a);
	if(a>0){
		printf("sign(%d) = 1",a);
	}
	if(a<0){
		printf("sign(%d) = -1",a);
	}if(a==0){
		printf("sign(%d) = 0",a);
	}
}
