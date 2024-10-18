int MonthDays(int year, int month){
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%4==0 && year%100!=0 || year%400==0){
		day[2]+=1;
	}
	return day[month];
}
