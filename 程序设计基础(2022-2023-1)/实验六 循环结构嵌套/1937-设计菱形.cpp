#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,i,j;
	int magicNumber; 
	cin>>n;
	for(i=1;i<=n;i++){
		// magic number lol
		magicNumber = (n-2*i+1)/2;
		// abs()
		if(magicNumber<0) magicNumber=-magicNumber;
		for(j=1;j<=magicNumber;j++)
			cout<<"-";
		for(j=1;j<=n-magicNumber*2;j++)
			cout<<"*";
		for(j=1;j<=magicNumber;j++)
			cout<<"-";
		cout<<endl;
	}
	return 0;
}
