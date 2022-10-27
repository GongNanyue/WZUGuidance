#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct treasure {

  int volume;
  int value;

  bool operator>(const treasure t1) const {
    return (double) this->value/(double) this->volume>(double) t1.value/(double) t1.volume;
  }
};
treasure a[N];

int main() {
  int v, n;
  cin>>v>>n;
  for(int i = 0; i<n; ++i){
    cin>>a[i].volume>>a[i].value;
  }
  sort(a, a+n, greater<treasure>());
  double sum = 0;
  for(int i = 0; i<n; ++i){
    if(a[i].volume>=v){
      sum += v*(double) a[i].value/a[i].volume;
      v = 0;
      break;
    }
    sum += a[i].value;
    v -= a[i].volume;
  }
  printf("%.2f\n",sum);
  return 0;
}
