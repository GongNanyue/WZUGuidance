#include <stdio.h>
#include <math.h>
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a==x){
			printf("%d",i);
			return 0;
		}
	}
	printf("Not Found");
}
