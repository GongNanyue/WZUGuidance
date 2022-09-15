#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	float a,b,c;
	cin>>a>>b>>c;
	printf("%.2f\n", min(min(a,b),min(b,c)));
	return 0;
}