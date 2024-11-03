int reverse( int number ){
	int f=1;
	int re=0;
	if(number<0){
		f=-1;
		number=-number;
	}
	while(number%10==0 && number>0){
		number/=10;
	}
	do{
		re*=10;
		re+=number%10;
		number/=10;
	}while(number>0);
	return f*re;
}
