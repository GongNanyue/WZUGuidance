#include <bits/stdc++.h>
using namespace std;

const int N = 60;
double a[N][N];

int main() {
  int n, m;
  cin>>n>>m;
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<m; ++j){
      cin>>a[i][j];
    }
  }
  for(int i = 0; i<n; ++i){
    double mx = a[i][0];
    for(int j = 1; j<m; ++j){
      if(mx<a[i][j])mx = a[i][j];
    }
    for(int j = 0; j<m; ++j){
      a[i][j] =a[i][j]/mx;
    }
  }

  cout.setf(ios::fixed);
  cout.precision(2);
  for(int i = 0; i<n  ; ++i){
    for(int j = 0; j<m; ++j){
      cout << a[i][j];
      if(j==m-1)
        cout << endl;
      else
        cout << " ";
    }
  }
  return 0;
}
