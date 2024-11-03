#include <stdio.h>
#include <limits.h>
#include <math.h>
int yh[11][11]={0};
int main(){
	yh[0][1]=1;
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<k-i;j++){
			printf(" ");
		}
		for(int j=1;j<=i;j++){
			printf("%4d",yh[i][j]);
		}
		printf("\n");
	}
}
