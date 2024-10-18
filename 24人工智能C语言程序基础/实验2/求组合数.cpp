#include <stdio.h>
#include<math.h>
double fact(int n);
int main(){
	int a=0,b=0;
	double re=0;
	scanf("%d%d",&a,&b);
	
	re=fact(b)/fact(a)/fact(b-a);
	
	printf("result = %.0f",re);
}
double fact(int n){
	double r=1;
	for(int i=1;i<=n;i++){
		r*=i;
	}
	return r;
}
