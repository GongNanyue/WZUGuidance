#include <stdio.h>
int main(){
	float x=0,y=0;
	scanf("%f",&x);
	if(x!=0){
		y=1/x;
	}
	printf("f(%.1f) = %.1f",x,y);
}
