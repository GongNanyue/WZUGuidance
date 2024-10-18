#include<stdio.h>
#include<math.h>
int if_prime(int n);

int main()
{    
	int a=0,b=0,sum=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++){
		int s=0;
		for(int j=0;j<i;j++){
			s*=10;
			s+=a;
		}
		sum+=s;
	}
	printf("s = %d",sum);
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
