#include <stdio.h>
#include <math.h>
int num[100]={0};
int main(){
	int n;
	scanf("%d",&n);
	n++;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n-1;i++){
		int max_pos=i;
		for(int j=i+1;j<n;j++){
			if(num[j]>num[max_pos]){
				max_pos=j;
			}
		}
		int t=num[i];
		num[i]=num[max_pos];
		num[max_pos]=t;
	}
	for(int i=n-1;i>=0;i++){
		printf("%d ",num[i]);
	}
}
