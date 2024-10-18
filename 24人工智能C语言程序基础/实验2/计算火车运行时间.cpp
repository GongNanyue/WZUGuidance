#include <stdio.h>
#include<math.h>
int main(){
	int a=0,b=0;
	scanf("%d%d",&a,&b);
	int at=0,bt=0;
	at=a/100*60+a%100;
	bt=b/100*60+b%100;
	int ct=bt-at;
	int c1=ct/60;
	int c2=ct%60;
	printf("%02d:%02d",c1,c2);
}
