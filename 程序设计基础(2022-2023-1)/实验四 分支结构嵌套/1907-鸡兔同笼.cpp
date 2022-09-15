#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	if(a%4==0) printf("%d %d\n", a/4, a/2);
	else if(a%2==0) printf("%d %d\n", a/4+1, a/2);
	else printf("0 0\n");
	return 0;
}