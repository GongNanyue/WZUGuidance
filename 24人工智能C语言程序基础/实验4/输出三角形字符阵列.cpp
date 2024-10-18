#include<stdio.h>
#include<math.h>

int main()
{    
	int a;
	scanf("%d",&a);
	char k='A';
	
	for(int i=a;i>0;i--){
		for(int j=0;j<i;j++){
			printf("%c ",k);
			k+=1;
		}
		printf("\n");
	}
}

