#include<stdio.h>
#include<math.h>

int main()
{    
	char a[100];
	scanf("%s",a);
	int i=0;
	while(a[i]!='\0'){
		printf("%c ",a[i]);
		i++;
	}
}

