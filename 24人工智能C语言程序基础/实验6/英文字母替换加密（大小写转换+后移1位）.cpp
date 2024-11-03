#include <stdio.h>
#include <math.h>
int main(){
	char a=' ';
	while(a!='\n'){
		scanf("%c",&a);
		if(a=='Z' || a=='z'){
			a-=25;
		}else if(a>='A' && a<='Z' || a>='a' && a<='z' ){
			a++;
		}
		if(a>='A' && a<='Z'){
			a-='A'-'a';
		}else if(a>='a' && a<='z'){
			a-='a'-'A';
		}
		printf("%c",a);
	}
}
