void ArrayShift( int a[], int n, int m ){
	m%=n;
	int ap[n];
	for(int i=0;i<n;i++){
		ap[i]=a[(i-m+n)%n];
	}
	for(int i=0;i<n;i++){
		a[i]=ap[i];
	}
}
