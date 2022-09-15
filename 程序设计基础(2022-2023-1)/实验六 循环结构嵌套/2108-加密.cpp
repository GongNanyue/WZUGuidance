#include<iostream>
#include<stdio.h>
using namespace std;

// lmao
int toAscbb(char c) {
	if(int(c)>=int('a') && int(c)<=int('z'))
		return int(c)-int('a')+1;
	if(int(c)>=int('A') && int(c)<=int('Z'))
		return int(c)-int('A')+27;
	return 0; // exception
}

int main() {
	int n,i,j;
	char ch;
	string s[114];
	cin>>n;
	getchar();
	for(i=0; i<n; i++)
		do {
			ch=getchar();
			if(ch!='\n')
				s[i].push_back(ch);
		} while(ch!='\n');
	for(i=0; i<n; i++) {
		for(j=0; j<s[i].length(); j++) {
			if(
				(int(s[i][j])>=int('A') && int(s[i][j])<=int('Z'))
				||
				(int(s[i][j])>=int('a') && int(s[i][j])<=int('z'))
			)
				cout<<toAscbb(s[i][j]);
			else
				cout<<s[i][j];
		}
		cout<<endl;
	}

	return 0;
}

