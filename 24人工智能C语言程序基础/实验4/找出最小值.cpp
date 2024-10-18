#include<stdio.h>
#include<math.h>
int main()
{    
	int a=0,min=999999999;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		int d=0;
		scanf("%d",&d);
		if(d<min){
			min=d;
		}
	}
	printf("min = %d",min);
}
