#include <stdio.h>
#include<math.h>
int main(){
	int a;
	scanf("%d",&a);
	int f=0;
	if(a<=2000 || a>=2101){
		printf("Invalid year!");
		return 0;
	}
	for(int i=2001;i<=a;i++){
		if((i%4==0 && i%100!=0) || i%400==0){
			printf("%d\n",i);
			f=1;
		}
	}
	if(f==0){
		printf("None");
	}
}
