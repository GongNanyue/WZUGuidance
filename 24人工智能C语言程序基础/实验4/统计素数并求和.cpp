#include<stdio.h>
#include<math.h>
int if_prime(int n);

int main()
{    
	int a=0,b=0,cnt=0,sum=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		cnt+=if_prime(i)*1;
		sum+=if_prime(i)*i;
	}
	printf("%d %d",cnt,sum);
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
