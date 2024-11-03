#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
int main(){
	char a[1000];
	int re=0;
	int k=0;
	for(int i=0;a[i]!='#';){
		scanf("%c",&a[i]);
		int n=-1;
		if(k==0 && a[i]=='-'){
			k=-1;
		}
		if(a[i]>='A' && a[i]<='F'){
			n=a[i]-'A'+10;
		}else if(a[i]>='a' && a[i]<='f'){
			n=a[i]-'a'+10;
		}else if(a[i]>='0' && a[i]<='9'){
			n=a[i]-'0';
		}
		if(n>=0){
			re*=16;
			re+=n;
			i++;
			if(k==0){
				k=1;
			}
		}
	}
	printf("%d",re*k);
}
