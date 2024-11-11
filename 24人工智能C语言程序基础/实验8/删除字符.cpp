
#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );

int main()
{
    char str[MAXN]="aaa", c;

    scanf("%c", &c);
    delchar(str, c);
    printf("%s\n", str);
    
    return 0;
}

void delchar( char *str, char c ){
	int del=0;
	for(int i=0;;i++){
		str[i]=str[i+del];
		if(str[i]=='\0'){
			return;
		}
		while(str[i]==c){
			del+=1;
			str[i]=str[i+del];
		}
	}
}
