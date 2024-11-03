#include <stdio.h>
#include <math.h>
int main(){
	char a=' ';
	int if_upper=1;
	while(a!='\n'){
		scanf("%c",&a);
		if(a>='a' && a<='z' && if_upper==1){
			a+='A'-'a';
		}
		if(a==' '){
			if_upper=1;
		}else{
			if_upper=0;
		}
		
		printf("%c",a);
	}
}
