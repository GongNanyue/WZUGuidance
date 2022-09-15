#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	char c;int x=0;int y;
	cin>>c>>y;
	if(int(c)<=int('Z') && int(c)>=int('A')) x=1*(int(c)-int('A')+1);
	else if(int(c)<=int('z') && int(c)>=int('a')) x=-1*(int(c)-int('a')+1);
	cout<<x+y<<endl;
	return 0;
}