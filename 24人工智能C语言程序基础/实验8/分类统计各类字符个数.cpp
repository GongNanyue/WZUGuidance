void StringCount( char *s ){
	int big=0,small=0,blank=0,num=0,other=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='Z'){
			big++;
		}else if(s[i]>='a' && s[i]<='z'){
			small++;
		}else if(s[i]>='0' && s[i]<='9'){
			num++;
		}else if(s[i]==' '){
			blank++;
		}else{
			other++;
		}
	}
	printf("%d %d %d %d %d",big,small,blank,num,other);
}
