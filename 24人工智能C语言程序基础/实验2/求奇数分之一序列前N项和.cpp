#include <stdio.h>
#include<math.h>
int main(){
	int x=0;
	scanf("%d",&x);
	double r=1;
	for(int i=1;i<x;i++){
		r+=1/(i*2+1.0);
	}
	printf("sum = %f",r);
}
