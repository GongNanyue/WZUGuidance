#include <stdio.h>
#include<math.h>
int main(){
	int c=0,l=0,b=0,d=0,o=0;
	char a;
	scanf("%d",&c);
	scanf("%c",&a);
	for(int i=1;i<=c;i++){
		scanf("%c",&a);
		//printf("%c",a);
		if((a>='a'&&a<='z') || (a>='A'&&a<='Z')){
			l++;
		}else if(a>='0'&&a<='9'){
			d++;
		}else if(a==' '||a=='\n'){
			b++;
		}else{
			o++;
		}
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",l,b,d,o);
}
