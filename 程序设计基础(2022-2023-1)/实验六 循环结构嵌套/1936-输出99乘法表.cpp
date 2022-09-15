#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int i,j;
	for(i=1; i<=9; i++) {
		for(j=1; j<=9; j++)
			printf("%d*%d=%-3d", i,j,i*j);
		cout<<endl;
	}
	return 0;
}