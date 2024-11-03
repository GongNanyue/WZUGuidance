#include <stdio.h>
#include <math.h>
int num[100]={0};
int main(){
	int n;
	scanf("%d",&n);
	int min_=0,max_=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]>num[max_]){
			max_=i;
		}
		if(num[i]<num[min_]){
			min_=i;
		}
	}
	int t=num[0];
	num[0]=num[min_];
	num[min_]=t;
	if(max_==0){
		max_=min_;
	}
	t=num[n-1];
	num[n-1]=num[max_];
	num[max_]=t;
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
}
