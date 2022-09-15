#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	char c[5];int i;
	for(i=0;i<5;i++)
		c[i] = getchar();
	if(c[0]==c[4] && c[1]==c[3]) printf("Yes.\n");
	else printf("No.\n");
	return 0; 
}