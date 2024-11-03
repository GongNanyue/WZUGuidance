#include <stdio.h>
#include <limits.h>
#include <math.h>
int fz[11][11]={0};
int main(){
	int n;
	scanf("%d",&n);
	int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int pos_cnt=1;
	for(int i=0;i<n;i++){
		fz[0][i]=i+1;
	}
	int now_cnt=n;
	int now_pos[2]={0,n-1};
	for(int i=n-1;i>0;i--){
		for(int k=0;k<2;k++){
			for(int j=0;j<i;j++){
				fz[now_pos[0]][now_pos[1]]=now_cnt;
				now_cnt++;
				now_pos[0]+=pos[pos_cnt][0];
				now_pos[1]+=pos[pos_cnt][1];
			}
			pos_cnt=(pos_cnt+1)%4;
		}
	}
	fz[now_pos[0]][now_pos[1]]=now_cnt;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%3d",fz[i][j]);
		}
		printf("\n");
	}
}
