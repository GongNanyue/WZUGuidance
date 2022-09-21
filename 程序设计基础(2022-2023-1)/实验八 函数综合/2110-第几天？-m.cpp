#include <iostream>
#include <stdio.h>
using namespace std;

bool isRunYear(int year) // 润年
{
  if (year % 4 == 0 && year % 100 != 0)
    return true;
  else if (year % 400 == 0)
    return true;
  else
    return false;
}

int getDay(int year, int month, int day)
{
  int tdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isRunYear(year))
    tdays[2] = 29;
  int sum = 0;
  for (int i = 1; i < month; i++)
    sum += tdays[i];
  sum += day;
  return sum;
}

int main()
{
  int year, month, day;
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &year);
    getchar();
    scanf("%d", &month);
    getchar();
    scanf("%d", &day);
    cout << getDay(year, month, day) << endl;
  }
  return 0;
}
