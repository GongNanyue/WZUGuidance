#include <stdio.h>
#include<math.h>
int main(){
	float p[5]={0,3,2.5,4.1,10.2};
	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
	for(int i=1;i<=5;i++){
		int a=0;
		scanf("%d",&a);
		if(a==0){
			break;
		}
		if(a<1||a>4){
			a=0;
		}
		printf("price = %.2f\n",p[a]);
	}
}
