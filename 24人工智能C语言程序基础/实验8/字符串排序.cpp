#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
	int n;
	char str[5][100]={""};
	char *sp[5];
    scanf("%s %s %s %s %s",&str[0],&str[1],&str[2],&str[3],&str[4]);
    for(int i=0;i<5;i++){
    	sp[i]=str[i];
	}
    for(int i=0;i<4;i++){
    	int min_=i;
    	for(int j=i+1;j<5;j++){
    		if(strcmp(sp[j], sp[min_])<0){
    			min_=j;
			}
		}
		if(min_!=i){
			char *t=sp[min_];
			sp[min_]=sp[i];
			sp[i]=t;
		}
			
	}
	printf("After sorted:\n");
	for(int i=0;i<5;i++){
		printf("%s\n",sp[i]);
	}
}
