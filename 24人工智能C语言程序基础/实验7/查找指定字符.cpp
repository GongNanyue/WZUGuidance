#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int main(){
	char a=' ';
	char tar;
	scanf("%c",&tar);
	int i=0,re=-1;
	getchar();
	while(a!='\n'){
		scanf("%c",&a);
		if(a==tar){
			re=i;
		}
		i++;
	}
	if(re==-1){
		printf("Not Found");
	}else{
		printf("index = %d",re);
	}
}
