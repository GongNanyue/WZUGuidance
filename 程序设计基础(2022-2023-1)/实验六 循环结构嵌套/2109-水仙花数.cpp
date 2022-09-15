#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	// more variables make me smarter, dude
	int n,i,j,a,b,f;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++){
		f=0;
		cin>>a>>b;
		for(;a<=b;a++){
			int i = a % 10, j = a / 10 % 10, k = a / 100;
			if(a==i*i*i+j*j*j+k*k*k){
				arr[f]=a;
				f+=1;
			}
		}
		if(f==0)
			cout<<"no"<<endl;
		else{
			for(i=0;i<f-1;i++)
				cout<<arr[i]<<" ";
			cout<<arr[f-1]<<endl;
		}
	}
	return 0;
}
