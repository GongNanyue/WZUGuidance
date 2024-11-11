int search( int list[], int n, int x ){
	int re=-1;
	for(int i=0;i<n;i++){
		if(list[i]==x){
			re=i;
			break;
		}
	}
	return re;
}
