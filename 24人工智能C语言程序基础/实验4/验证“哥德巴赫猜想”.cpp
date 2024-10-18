#include<stdio.h>
#include<math.h>
int if_prime(int n);

int main()
{    
	int a=0;
	scanf("%d",&a);
	for(int i=2;i<=a;i++){
		if(if_prime(i)==1 && if_prime(a-i)==1){
			printf("%d = %d + %d",a,i,a-i);
			return 0;
		}
	}
}

int if_prime(int n){
	if(n<=1){
		return 0;
	}
	for(int i=2;i<(int)sqrt(n)+1;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
