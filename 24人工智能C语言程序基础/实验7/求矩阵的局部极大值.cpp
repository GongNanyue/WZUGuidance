#include <stdio.h>
#include <limits.h>
#include <math.h>
int num[25][25]={0};
int maxnum[1000][3]={};
int maxcnt=0;
int main(){
	int m,n;
	int pos[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	scanf("%d%d",&m,&n);
	for(int i=0;i<=m+1;i++){
		for(int j=0;j<=n+1;j++){
			num[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int if_max=1;
			for(int k=0;k<4;k++){
				if(num[i][j]<=num[i+pos[k][0]][j+pos[k][1]]){
					if_max=0;
					break;
				}
			}
			if(if_max){
				maxnum[maxcnt][0]=num[i][j];
				maxnum[maxcnt][1]=i;
				maxnum[maxcnt][2]=j;
				maxcnt++;
			}
		}
	}
	if(maxcnt>0){
		for(int i=0;i<maxcnt;i++){
			printf("%d %d %d\n",maxnum[i][0],maxnum[i][1],maxnum[i][2]);
		}
	}else{
		printf("None %d %d",m,n);
	}
}
