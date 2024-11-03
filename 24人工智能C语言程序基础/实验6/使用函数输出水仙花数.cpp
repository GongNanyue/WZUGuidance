#include <math.h>
int narcissistic( int number ){
	int number_t=number,number_t2=number,t=0;
	do{
		number_t/=10;
		t++;
	}while(number_t>0);
	int re=0;
	do{
		re+=pow(number_t2%10,t);
		number_t2/=10;
	}while(number_t2>0);
	if(re==number){
		return 1;
	}
	return 0;
}
void PrintN( int m, int n ){
	for(int i=m+1;i<n;i++){
		if(narcissistic(i)){
			printf("%d\n",i);
		}
	}
}
