#include <stdio.h>
#include <math.h>
int num[10]={0};
int main(){
	int n;
	scanf("%d",&n);
	int blank=0;
	char a=' ';
	getchar();
	while(blank<n){
		scanf("%c",&a);
		if(a==' '|| a=='\n'){
			blank++;
		}else{
			num[a-'0']++;
		}
	}
	int max_int=0;
	for(int i=0;i<10;i++){
		if(num[i]>max_int){
			max_int=num[i];
		}
	}
	printf("%d:",max_int);
	for(int i=0;i<10;i++){
		if(num[i]==max_int){
			printf(" %d",i);
		}
	}
}
