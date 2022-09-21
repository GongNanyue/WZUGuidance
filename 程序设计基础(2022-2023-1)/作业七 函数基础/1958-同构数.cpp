#include <iostream>
using namespace std;

int main()
{
  int i, j, s;
  bool f;
  for (i = 1; i <= 99; i++)
  {
    f = true;
    j = i;
    s = i * i;
    while (j != 0)
    {
      if (j % 10 == s % 10)
      {
        s = s / 10;
        j = j / 10;
        continue;
      }
      s = s / 10;
      j = j / 10;
      f = false;
    }
    if (f)
      cout << i << " ";
  }
  cout<<endl;
  return 0;
}
