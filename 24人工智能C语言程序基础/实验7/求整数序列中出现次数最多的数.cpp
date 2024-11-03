#include <stdio.h>
#include <math.h>
int num[1001]={0};
int numcnt[1001]={0};
int  cnt=0;
int main(){
	int n;
	scanf("%d",&n);
	int max_=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		int if_new=1;
		for(int i=0;i<cnt;i++){
			if(num[i]==a){
				numcnt[i]++;
				if(numcnt[i]>numcnt[max_]){
					max_=i;
				}
				if_new=0;
				break;
			}
		}
		if(if_new){
			num[cnt]=a;
			numcnt[cnt]=1;
			cnt++;
			if(numcnt[i]>numcnt[max_]){
				max_=i;
			}
		}
	}
	printf("%d %d",num[max_],numcnt[max_]);
}
