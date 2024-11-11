#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
int main(){
	int n;
	double sum=0,max_=-99999,min_=99999;
    scanf("%d",&n);
	//double *f = (double*)malloc(n*sizeof(double));
	for(int i=0;i<n;i++){
		double fw=0;
		scanf("%lf",&fw);
		sum+=fw;
		if(fw>max_){
			max_=fw;
		}
		if(fw<min_){
			min_=fw;
		}
	}
	printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf",sum/n,max_,min_);
}
