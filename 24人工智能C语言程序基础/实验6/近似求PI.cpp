#include <stdio.h>
#include <math.h>
int main(){
	double eps;
	scanf("%lf",&eps);
	double t=1,re=0,fm=1,fz=1;
	for(int i=0;t>=eps;i++){
		if(i>0){
			fz*=i;
		}
		fm*=(2*i+1);		
		t=fz/fm;
		re+=t;
	}
	if(eps>1){
		re=1;
	}
	printf("PI = %.5lf",re*2);
}
