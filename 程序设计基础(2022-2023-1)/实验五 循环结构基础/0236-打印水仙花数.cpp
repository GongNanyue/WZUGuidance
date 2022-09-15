#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int i,j;
	for(i=100;i<999;i++){
		j=(i/100)*(i/100)*(i/100)
				+(i/10%10)*(i/10%10)*(i/10%10)
				+(i%10)*(i%10)*(i%10);
		if(j==i) printf("%d\n", j); 
	}
	return 0; 
}