#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
	char ip_[33]={};
	char *zz=ip_;
	scanf("%s",&ip_);
	int num[4]={0};
	for(int i=0;i<4;i++){
		char h[9];
		strncpy(h,zz,8);
		zz+=8;
		h[8]='\0';
		num[i]=(unsigned int)strtol(h, NULL, 2);
		printf("%d",num[i]);
		if(i<3){
			printf(".");
		}
	}
}
