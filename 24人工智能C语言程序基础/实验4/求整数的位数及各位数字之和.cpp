#include<stdio.h>
#include<math.h>
int main()
{    
	int a=0,sum=0,cnt=0;
	scanf("%d",&a);
	while(a>0){
		int d=a%10;
		sum+=d;
		cnt+=1;
		a/=10;
	}
	printf("%d %d",cnt,sum);
}
