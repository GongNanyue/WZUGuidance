#include<stdio.h>
#include<math.h>
int if_w(int n);

int main()
{    
	int a=0,b=0,f=1;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		if(if_w(i)==1){
			f=0;
		}
	}
	if(f){
		printf("None");
	}
}

int if_w(int n){
	int sum=0,y[1000]={},cnt=0;
	for(int i=1;i<n;i++){
		if(n%i==0){
			sum+=i;
			y[cnt]=i;
			cnt+=1;
		}
	}
	if(sum==n){
		printf("%d = ",n);
		for(int i=0;i<cnt-1;i++){
			printf("%d + ",y[i]);
		}
		printf("%d\n",y[cnt-1]);
		return 1;
	}
	return 0;
}
