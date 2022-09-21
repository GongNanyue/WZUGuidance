#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int s(int n, int x)
{
  int s = 0;
  while (n != 0)
  {
    s += n % x;
    n /= x;
  }
  return s;
}

bool sky(int n)
{
  if (s(n, 10) == s(n, 16) && s(n, 10) == s(n, 12))
    return true;
  else
    return false;
}

int main()
{
  int i, n, s;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    cin >> s;
    if (sky(s))
      cout << s << " is a Sky Number." << endl;
    else
      cout << s << " is not a Sky Number." << endl;
  }
  return 0;
}
