#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int joseph(int m, int n)
{
  bool monkey[1024]; // 114 is not enough
  int count = 0;
  int t = n;
  int j = 0;
  for (int i = 0; i < m; i++)
  {
    monkey[i] = true;
  }
  while (count != m - 1)
  {

    if (j == m)
      j = 0;
    if (monkey[j])
    {
      t--;
      if (t == 0)
      {
        monkey[j] = false;
        count++;
        t = n;
      }
    }
    j++;
  }
  for (int i = 0; i < m; i++)
  {
    if (monkey[i])
    {
      return i + 1;
    }
  }
}

int main()
{
  int m, n;
  while (cin >> m >> n && !(!m && !n))
  {
    cout << joseph(m, n) << endl;
  }
  return 0;
}
