#include <stdio.h>
#include <math.h>
int num[20]={0};
int num1[20]={0};
int re[40]={0};
int cnt=0;
int main(){
	int n,n1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		scanf("%d",&num1[i]);
	}
	for(int i=0;i<n;i++){
		int out=1;
		for(int j=0;j<n1;j++){
			if(num1[j]==num[i]){
				out=0;
			}
		}
		for(int j=0;j<cnt;j++){
			if(re[j]==num[i]){
				out=0;
			}
		}
		if(out){
			re[cnt]=num[i];
			cnt++;
		}
		
	}
	for(int i=0;i<n1;i++){
		int out=1;
		for(int j=0;j<n;j++){
			if(num[j]==num1[i]){
				out=0;
			}
		}
		for(int j=0;j<cnt;j++){
			if(re[j]==num1[i]){
				out=0;
			}
		}
		if(out){
			re[cnt]=num1[i];
			cnt++;
		}
	}
	printf("%d",re[0]);
	for(int i=1;i<cnt;i++){
		printf(" %d",re[i]);
	}
}
