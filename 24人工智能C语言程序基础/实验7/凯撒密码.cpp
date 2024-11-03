#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int main(){
	char a[1000];
	int offset=0;
	fgets(a, sizeof(a), stdin);
	a[strcspn(a, "\n")] = 0;
	scanf("%d",&offset);
	offset=offset%26;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]>='A' && a[i]<='Z'){
			a[i]=(a[i]+offset-'A'+26)%26+'A';
		}
		if(a[i]>='a' && a[i]<='z'){
			a[i]=(a[i]+offset-'a'+26)%26+'a';
		}
		printf("%c",a[i]);
	}
}
