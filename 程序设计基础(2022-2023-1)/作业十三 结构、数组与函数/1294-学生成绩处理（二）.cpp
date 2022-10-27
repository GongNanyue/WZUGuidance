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
st a[5];

int main() {
  for(int i = 0; i<5; ++i){
    cin>>a[i].name>>a[i].m>>a[i].c>>a[i].e;
    a[i].cal();
  }
  sort(a,a+5,greater<st>());
  cout.setf(ios::fixed);
  cout.precision(1);
  for(int i = 0; i<5; ++i){
    cout<<a[i].name<<" "<<a[i].m<<" "<<a[i].c<<" "<<a[i].e<<" "<<a[i].sum<<endl;
  }
  return 0;
}
