#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
	int i;
	bool flag=true;
	for(i=2;i<=(n+1)/2;i++)
		if(n%i==0)
			flag=false;
	return flag;
}
int main() {
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		if(isPrime(j))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
    return 0;
}
