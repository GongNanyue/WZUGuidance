#include <bits/stdc++.h>
using namespace std;
struct st {

  char name[30];
  double c;//chinese
  double m;//math
  double e;//english
  double sum;

  bool operator<(const st s1) const {
    return this->sum<s1.sum;
  }

  bool operator>(const st s1) const {
    return this->sum>s1.sum;
  }

  void cal() {
    this->sum = (this->c+this->m+this->e);
  }
};
const int N = 110;
st a[N];

int main() {
  int n;
  cin>>n;
  for(int i = 0; i<n; ++i){
    cin>>a[i].name>>a[i].m>>a[i].c>>a[i].e;
    a[i].cal();
  }
  sort(a, a+n, greater<st>());
  cout.setf(ios::fixed);
  cout.precision(2);
  for(int i = 0; i<n; ++i){
    cout<<a[i].name << " " << a[i].sum<<endl;
  }
  return 0;
}
