#include <stdio.h>
#include<math.h>
int main(){
	int a=0,b=0,c=0,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	if(b>c){
		t=b;
		b=c;
		c=t;
	}
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	printf("%d->%d->%d",a,b,c);
}
