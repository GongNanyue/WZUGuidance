#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int i;
	for(i=0;i<=300;i+=20)
		printf("%d    %d\n", i, int((5.0/9.0)*(i-32))); 
	return 0; 
}