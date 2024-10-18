int CountDigit( int number, int digit ){
	int re=0;
	if(number<0){
		number*=-1;
	}
	do{
		if(number%10==digit){
			re+=1;
		}
		number/=10;
	}while(number>0);
	return re;
}
