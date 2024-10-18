#include <stdio.h>
#include<math.h>
int main(){
	int a=0,b=0;
	scanf("%d%d",&a,&b);
	if(a>999||a<100 || b>999||b<100 || a>b){
		printf("Invalid Value.");
		return 0;
	}
	for(int i=a;i<=b;i++){
		int v,b,n;
		v=i/100;
		b=i%100/10;
		n=i%10;
		if(v*v*v+b*b*b+n*n*n==i){
			printf("%d\n",i);
		}
	}
}
