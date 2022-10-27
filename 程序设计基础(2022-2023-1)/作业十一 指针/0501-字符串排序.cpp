#include <bits/stdc++.h>
using namespace std;

const int N = 110;
string as[N];

int main() {
  int n;
  cin>>n;
  getchar();
  for(int i = 0; i<n; ++i){
    getline(cin,as[i]);
  }
  sort(as,as+n);
  for(int i = 0; i<n; ++i){
    cout << as[i] << endl;
  }
  return 0;
}
