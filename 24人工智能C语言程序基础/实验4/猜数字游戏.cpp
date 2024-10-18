#include<stdio.h>
#include<math.h>
int if_prime(int n);

int main()
{    
	int a=0,b=0,s=1,cnt=0;
	scanf("%d%d",&a,&b);
	while(s>=0){
		scanf("%d",&s);
		cnt+=1;
		if(s<0){
			printf("Game Over");
			return 0;
		}
		if(s>a){
			printf("Too big\n");
		}else if(s<a){
			printf("Too small\n");
		}else{
			break;
		}
		if(cnt>=b){
			printf("Game Over");
			return 0;
		}
	}
	if(cnt==1){
		printf("Bingo!");
	}else if(cnt<=3){
		printf("Lucky You!");
	}else{
		printf("Good Guess!");
	}
}

int if_prime(int n){
	if(n<=1){
		return 0;
	}
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
