#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
	int m,n;
	int a;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		int sum=0; 
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
}
