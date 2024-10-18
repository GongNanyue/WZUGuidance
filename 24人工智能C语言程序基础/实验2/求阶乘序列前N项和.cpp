#include <stdio.h>
#include<math.h>
long long fact(int n);
int main(){
	long long a=0,sum=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		sum+=fact(i);
	}
	printf("%d",sum);
}
long long fact(int n){
	long long r=1;
	for(int i=1;i<=n;i++){
		r*=i;
	}
	return r;
}
