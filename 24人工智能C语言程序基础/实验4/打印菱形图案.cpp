#include<stdio.h>
#include<math.h>

int main()
{    
	int a;
	scanf("%d",&a);
	
	for(int i=1;i<=a/2+1;i++){
		for(int j=0;j<a/2-i+1;j++){
			printf("  ");
		}
		for(int j=0;j<i*2-1;j++){
			printf("* ");
		}
		printf("\n");
	}
	for(int i=a/2;i>0;i--){
		for(int j=0;j<a/2-i+1;j++){
			printf("  ");
		}
		for(int j=0;j<i*2-1;j++){
			printf("* ");
		}
		printf("\n");
	}
}

