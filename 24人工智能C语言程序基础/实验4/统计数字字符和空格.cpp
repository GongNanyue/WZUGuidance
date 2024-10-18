#include<stdio.h>
#include<math.h>
int main()
{    
	char a=' ';
	int blank=0,digit=0,other=0;
	while(1){
		a=getchar();
		if(a=='\n'){
			break;
		}
		if(a==' '){
			blank+=1;
		}else if(a>='0' && a<='9'){
			digit+=1;
		}else{
			other+=1;
		}		
	}
	printf("blank = %d, digit = %d, other = %d",blank, digit, other);
}
