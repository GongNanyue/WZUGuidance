#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
	int k;
	scanf("%d",&k);
	for(int w=0;w<k;w++){
		int n;
		scanf("%d",&n);
		int if_yes=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int a;
				scanf("%d",&a);
				if(j<i && a!=0){
					if_yes=0;
				}
			}
		}
		if(if_yes){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
