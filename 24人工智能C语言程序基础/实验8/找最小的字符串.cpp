#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
	int n;
	char min_[100]="";
    scanf("%d",&n);
	for(int i=0;i<n;i++){
		char now[100];
    	scanf("%s",&now);
    	if(strcmp(now, min_)<0 || min_[0]=='\0'){
    		for(int j=0;j<100;j++){
    			min_[j]=now[j];
			}
		}
	}
	printf("Min is: %s",min_);
}
