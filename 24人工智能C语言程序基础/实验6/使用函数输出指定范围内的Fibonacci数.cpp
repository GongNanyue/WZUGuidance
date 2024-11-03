int fib( int n ){
	if(n<3){
		return 1;
	}
	return fib(n-2)+fib(n-1);
}
void PrintFN( int m, int n ){
	int if_none=1;
	int i;
	for(i=1;fib(i)<m;i++);
	int first=1;
	for(;fib(i)<=n;i++){
		if(!first){
			printf(" ");
		}
		first=0;
		printf("%d",fib(i));
		if_none=0;
	}
	if(if_none){
		printf("No Fibonacci number");
	}
}
