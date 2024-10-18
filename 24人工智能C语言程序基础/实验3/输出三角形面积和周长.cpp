#include <stdio.h>
#include<math.h>
int main(){
	int a,b,c;
	double s;
	double area,per;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b<=c || a+c<=b || c+b<=a){
		printf("These sides do not correspond to a valid triangle");
		return 0;
	}
	per=a+b+c;
	s=per/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("area = %.2lf; perimeter = %.2lf",area,per);
}
