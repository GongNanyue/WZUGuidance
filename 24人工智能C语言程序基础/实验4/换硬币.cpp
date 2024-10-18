#include<stdio.h>
#include<math.h>

int main()
{    
	int a,cnt=0;
	scanf("%d",&a);
	
	for(int i=a/5;i>0;i--){
		for(int j=a/2;j>0;j--){
			for(int k=a/1;k>0;k--){
				if(i*5+j*2+k==a){
					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,i+j+k);
					cnt++;
				}
				if(i*5+j*2+k==a)break;
			}
		}
	}
	printf("count = %d",cnt);
}

