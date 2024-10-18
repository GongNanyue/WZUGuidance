#include <stdio.h>
#include<math.h>
int main(){
	float a=0,b=0;
	scanf("%f",&a);
	if(a>=0&&a<=50){
		b=a*0.53;
	}else if(a>=0){
		b=50*0.53+(a-50)*0.58;
	}else{
		printf("Invalid Value!");
		return 0;
	}
	printf("cost = %.2f",b);
}
