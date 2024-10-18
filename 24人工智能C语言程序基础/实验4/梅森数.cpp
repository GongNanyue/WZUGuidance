#include<stdio.h>
#include<math.h>
int if_prime(int n);

int main()
{    
	int a=0,f=1;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		int m=pow(2,i)-1;
		if(if_prime(m)==1){
			printf("%d\n",m);
			f=0;
		}
	}
	if(f){
		printf("None");
	}
}

int if_prime(int n){
	if(n<=1){
		return 0;
	}
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
