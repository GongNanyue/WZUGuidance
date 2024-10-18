double mypow( double x, int n ){
	if(n==0){
		return 1;
	}
	if(n==1){
		return x;
	}
	if(n%2==0){
		return mypow(x,n/2)*mypow(x,n/2);
	}else{
		return mypow(x,n/2)*mypow(x,n/2)*x;
	}
}
