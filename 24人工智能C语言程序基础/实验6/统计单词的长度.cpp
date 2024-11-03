#include <stdio.h>
#include <math.h>
int main(){
	char a=' ';
	int cnt=0;
	int all_blank=1;
	while(a!='\n'){
		scanf("%c",&a);
		if(a==' ' || a=='\n'){
			if(cnt>0){
				printf("%d ",cnt);
			}
			
			cnt=0;
		}else{
			all_blank=0;
			cnt++;
		}
	}
	if(all_blank){
		printf("0 ");
	}
}
