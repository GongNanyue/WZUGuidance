#include <iostream>
using namespace std;
int main()
{
  int m, n, i, j, s = 0;
  bool f;
  while (cin >> m >> n && m && n)
  {
    for (i = m; i <= n; i++)
    {
      j = i;
      f = true;
      while (j != 0)
      {
        if (j % 10 == 4 || j % 100 == 62)
          f = false;
        j = j / 10;
      }
      if (f)
        s += 1;
    }
    cout << s << endl;
  }
  return 0;
}
