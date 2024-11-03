#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int main(){
	char a=' ';
	while(a!='\n'){
		scanf("%c",&a);
		if(a>='A' && a<='Z'){
			a='Z'-a+'A';
		}
		printf("%c",a);
	}
}
