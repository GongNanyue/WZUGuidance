int prime( int p ){
	if(p<2){
		return 0;
	}
	for(int i=2;i<=sqrt(p);i++){
		if(p%i==0){
			return 0;
		}
	}
	return 1;
}
int PrimeSum( int m, int n ){
	int sum=0;
	for(int i=m;i<=n;i++){
		sum+=i*prime(i);
	}
	return sum;
}
