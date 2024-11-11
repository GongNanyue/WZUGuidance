void sort( int a[], int n ){
	for(int i=0;i<n-1;i++){
		int min_=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[min_]){
				min_=j;
			}
		}
		int t=a[min_];
		a[min_]=a[i];
		a[i]=t;
	}
}
