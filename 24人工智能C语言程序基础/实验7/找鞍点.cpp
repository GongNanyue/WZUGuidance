#include <stdio.h>
#include <limits.h>
#include <math.h>
int fz[8][8]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&fz[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int if_an=1;
			for(int h=0;h<n;h++){
				if(h==i){
					continue;
				}
				if(fz[i][h]>fz[i][j]){
					if_an=0;
					break;
				}
			}
			for(int h=0;h<n;h++){
				if(h==i){
					continue;
				}
				if(fz[h][j]<fz[i][j]){
					if_an=0;
					break;
				}
			}
			if(if_an){
				printf("%d %d",i,j);
				return 0;
			}
		}
			
	}
	printf("NONE");
}
