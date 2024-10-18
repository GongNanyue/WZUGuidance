#include<stdio.h>
#include<math.h>
int if_s(int n);
int m[10]={};

int main()
{    
	int a=0;
	scanf("%d",&a);
	for(int i=0;i<=9;i++){
		m[i]=pow(i,a);
	}
	for(int i=pow(10,a-1);i<pow(10,a);i++){
		if(if_s(i)==1){
			printf("%d\n",i);
		}
	}
}

int if_s(int n){
	int sum=0,s=n;
	while(n>0){
		sum+=m[n%10];
		if(sum>s){
			return 0;
		}
		n/=10;
	}
	if(sum==s){
		return 1;
	}
	return 0;
}
