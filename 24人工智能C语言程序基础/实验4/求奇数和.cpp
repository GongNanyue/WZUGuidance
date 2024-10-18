# include <stdio.h>
int main()
{    
    int a=1,sum=0;
    scanf("%d",&a);
    while(a>0){
    	if(a%2==1){
    		sum+=a;
		}
    	scanf("%d",&a);
	}
    printf("%d",sum);
}
