#include <bits/stdc++.h>
using namespace std;
struct st {
  char id[30];
  char name[30];
  double c;//chinese
  double m;//math
  double e;//english
  double avg;

  bool operator<(const st s1) const {
    return this->avg<s1.avg;
  }

  bool operator>(const st s1) const {
    return this->avg>s1.avg;
  }

  void cal() {
    this->avg = (this->c+this->m+this->e)/3;
  }
};
st a[5];

int main() {
  for(int i = 0; i<5; ++i){
    cin>>a[i].id>>a[i].name>>a[i].m>>a[i].c>>a[i].e;
    a[i].cal();
  }
  sort(a, a+5);
  cout.setf(ios::fixed);
  cout.precision(1);
  for(int i = 0; i<5; ++i){
    cout<<a[i].id<<" "<<a[i].name<<" "<<a[i].m<<" "<<a[i].c<<" "<<a[i].e<<" "<<a[i].avg<<endl;
  }
  return 0;
}
