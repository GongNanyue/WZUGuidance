#include <stdio.h>
#include <limits.h>
#include <math.h>
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int year,month,day;
	scanf("%d/%d/%d",&year,&month,&day);
	if(year%100!=0 && year%4==0 || year%400==0){
		md[2]=29;
	}
	int re=day;
	for(int i=1;i<month;i++){
		re+=md[i];
	}
	printf("%d",re);
}
