#include <bits/stdc++.h>

using namespace std;
double x[100], y[100];
double distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf %lf", &x[i], &y[i]);
  }
  double maxdistance = 0.0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      maxdistance = max(maxdistance, distance(x[i], y[i], x[j], y[j]));
    }
  }
  printf("%.4lf\n", maxdistance);
  return 0;
}
