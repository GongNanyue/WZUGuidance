
int calcDays(int year, int month, int day){
  int days[12]={0,31,28,31,30,31,30,31,31,30,31,30};
  int sum = 0;
  for(int i=0;i<month;i++){
    sum += days[i];
  }
  sum += day;
  

  if(month>2&&(year%4 == 0&& year %100 !=  0|| year %400 == 0))++sum;
  return sum;
}
