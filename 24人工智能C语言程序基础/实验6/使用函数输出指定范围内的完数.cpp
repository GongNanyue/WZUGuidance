int factorsum( int number ){
	int re=0;
	for(int i=1;i<number;i++){
		if(number%i==0){
			re+=i;
		}
	}
	return re;
}
void fuckyou(int number){
	printf("%d = 1",number);
	for(int i=2;i<number;i++){
		if(number%i==0){
			printf(" + %d",i);
		}
	}
	printf("\n");
}
void PrintPN( int m, int n ){
	int if_none=1;
	for(int i=m;i<=n;i++){
		if(factorsum(i)==i){
			if_none=0;
			fuckyou(i);
		}
	}
	if(if_none){
		printf("No perfect number");
	}
}
