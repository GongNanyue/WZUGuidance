void hollowPyramid ( int n ){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			printf(" ");
		}
		printf("%d",i);
		if(i>1){
			for(int j=0;j<i*2-3;j++){
				printf(" ");
			}
			printf("%d",i);
		}
		printf("\n");
	}
	for(int i=0;i<2*n-1;i++){
		printf("%d",n);
	}
}
