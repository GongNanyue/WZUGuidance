int prime(int n){
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
void Goldbach( int n ){
	int cnt=0;
	for(int i=3;i<=n/2;i+=2){
		if(prime(i) && prime(n-i)){
			printf("%d=%d+%d",n,i,n-i);
			return;
		}
	}
}
