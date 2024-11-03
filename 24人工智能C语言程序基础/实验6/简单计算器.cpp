#include <stdio.h>
#include <math.h>
//#include <iostream>
//using namespace std;
int if_err=0;
int opr(int a,char op,int b);
int main(){
	char a=' ';
	int now_int=0,last_int=0;
	char last_op='+';
	while(a!='\n'){
		scanf("%c",&a);
		if(a>='0' && a<='9'){
			now_int*=10;
			now_int+=a-'0';
		}else{
			//cout<<last_int<<last_op<<now_int<<endl;
			last_int=opr(last_int,last_op,now_int);
			now_int=0;
			last_op=a;
			if(if_err){
				printf("ERROR");
				return 0;
			}
		}
	}
	printf("%d",last_int);
}

int opr(int a,char op,int b){
	if(op=='*'){
		return a*b;
	}
	if(op=='+'){
		return a+b;
	}
	if(op=='-'){
		return a-b;
	}
	if(op=='/'){
		if(b==0){
			if_err=1;
			return -1;	
		}
		return a/b;
	}
	if(op=='='){
		return a;
	}
	if_err=1;
	return -1;
}
