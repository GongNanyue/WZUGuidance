int calcSumOfNumber(int x){
  int sum = 0;
  while(x){
    sum += x%10;
    x/=10;
  }
  
  
  return sum;
  
}
