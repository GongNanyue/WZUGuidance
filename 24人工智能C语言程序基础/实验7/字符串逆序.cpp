#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int main(){
	char a[100];
	int i=0;
	do{
		scanf("%c",&a[i++]);
	}while(a[i-1]!='\n');
	for(i-=2;i>=0;i--){
		printf("%c",a[i]);
	}
}
