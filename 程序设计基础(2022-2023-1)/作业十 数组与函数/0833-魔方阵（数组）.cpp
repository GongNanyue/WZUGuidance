#include <bits/stdc++.h>

using namespace std;
int a[30][30];

int main() {
  int N;
  cin>>N;
  int count = 1;
  int row = 0, cul = N / 2;
  while (count <= N*N)
  {
    a[row][cul] = count;
    int i = row;
    int j = cul;
    if (i == 0)
    {
      i = N - 1;
    }
    else
    {
      i = i - 1;
    }
    j = (j + 1) % N;
    if (a[i][j]!=0||(row==0&&cul==N-1))
    {
      i = row + 1;
      j = cul;
    }
    row = i;
    cul = j;
    count++;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
