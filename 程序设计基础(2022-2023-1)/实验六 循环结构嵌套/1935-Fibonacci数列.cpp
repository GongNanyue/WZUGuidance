#include<iostream>
using namespace std;
int main() {
	int tmp,n=0,t[256];
	int f[47]={0,1};
	cin>>tmp;
	while(tmp!=-1){
		t[n]=tmp;
		n+=1;
		cin>>tmp;
	}
	for(tmp=2;tmp<47;tmp++)
		f[tmp]=f[tmp-2]+f[tmp-1];
	for(tmp=0;tmp<n;tmp++)
		cout<<f[t[tmp]]<<endl; 
	return 0;
}
