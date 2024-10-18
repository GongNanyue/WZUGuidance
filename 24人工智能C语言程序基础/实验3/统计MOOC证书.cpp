#include <stdio.h>
#include<math.h>
int main(){
	int a=0,t=0,y=0,u=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		int b=0;
		scanf("%d",&b);
		if(b>=85){
			t++;
		}else if(b>=60){
			y++;
		}else{
			u++;
		}
	}
	printf("%d %d %d",t,y,u);
}
