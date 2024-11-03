#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int char_[26]={0};
int main(){
	char a[1000];
	fgets(a,sizeof(a),stdin);
	a[strcspn(a, "\n")] = 0;
	int no=1;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]>'Z' || a[i]<'A'){
			continue;
		}
		a[i]-='A';
		if(char_[a[i]]==0){
			printf("%c",a[i]+'A');no=0;
		}
		char_[a[i]]=1;
	}
	if(no){
		printf("Not Found");
	}
}
