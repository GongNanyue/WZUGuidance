#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
	int cnt=0;
	char a=' ';
	while(a!='\n'){
		scanf("%c",&a);
		if(a>='A'&&a<='Z'&&a!='A'&&a!='E'&&a!='I'&&a!='O'&&a!='U'){
			cnt++;
		}
	}
	printf("%d",cnt);
}
