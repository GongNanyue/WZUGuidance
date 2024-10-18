#include<stdio.h>
#include<math.h>
int rabbit(int m);

int main()
{    
	int a=0;
	scanf("%d",&a);
	int sum=1,cnt=0;
	while(sum<a){
		cnt+=1;
		sum=rabbit(cnt);
	}
	if(a==1){
		cnt=1;
	}
	printf("%d",cnt);
}
int rabbit(int m){
	if(m<3){
		return 1;
	}
	return rabbit(m-1)+rabbit(m-2);
}
