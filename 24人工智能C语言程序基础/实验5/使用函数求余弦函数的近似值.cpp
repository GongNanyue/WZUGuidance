double jc( int n){
	double re=1;
	for(int i=2;i<=n;i++){
		re*=i;
	}
	return re;
}
double funcos( double e, double x ){
	
	double re=1;
	double n=1;
	int k=-1;
	for(int i=1;fabs(n)>=e;i++){
		n=pow(x,2*i)/jc(2*i)*k;
		re+=n;
		k*=-1;
	}
	return re;
}
