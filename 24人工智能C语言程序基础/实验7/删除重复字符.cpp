#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int char_[1000]={0};
int main(){
	char a[1000];
	fgets(a,sizeof(a),stdin);
	a[strcspn(a, "\n")] = 0;
	int no=1;
	for(int i=0;a[i]!='\0';i++){
		if(char_[a[i]]==0){
			printf("%c",a[i]);
		}
		char_[a[i]]=1;
	}
	for(int i=0;i<1000;i++){
		if(char_[i]==1){
			printf("%c",i);
		}
	}
}
