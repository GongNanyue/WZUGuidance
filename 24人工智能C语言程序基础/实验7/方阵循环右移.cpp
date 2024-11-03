#include <stdio.h>
#include <limits.h>
#include <math.h>
int fz[8][8]={0};
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&fz[i][(j+m)%n]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",fz[i][j]);
		}
		printf("\n");
	}
}
