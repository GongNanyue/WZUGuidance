void strmcpy( char *t, int m, char *s ){
	int l=0;
	for(l;t[l]!='\0';l++);
	if(m-1>=l){
		s[0]='\0';
		return;
	}
	for(int i=0;t[i+m-1]!='\0';i++){
		s[i]=t[i+m-1];
		s[i+1]='\0';
	}
}
