
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct Point_ {
  double x;
  double y;
} Point;
double distance(Point *p1, Point *p2) {
  return sqrt(pow(((p1->x) - (p2->x)), 2) + pow(((p1->y) -( p2->y)), 2));
}
int main() {

  Point p1, p2;
  scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
  printf("%.2lf\n", distance(&p1,&p2));
  return 0;
}

2035-距离
