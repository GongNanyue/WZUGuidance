#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	printf("%d %d %d %d %d\n",
		a+b+c,
		(a+b+c)/3,
		a*b*c,
		min(min(a,b),min(b,c)),
		max(max(a,b),max(b,c))
	);
	return 0;
}