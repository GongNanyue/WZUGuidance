#include <stdio.h>
#include <math.h>
int num[100]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	printf("%d",num[n-1]);
	for(int i=n-2;i>=0;i--){
		printf(" %d",num[i]);
	}
}
