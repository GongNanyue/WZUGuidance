
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct Student_ {
  double C;
  double english;
  double math;
  double sum;
} Student;

void initStudent(Student *s);
void countStudent(Student *s);
void sortStudent(Student *s, int cnt);
int cmp(const void *s1, const void *s2);
void displayStudent(Student *s) {
  printf("%.1lf %.1lf %.1lf %.1lf\n", s->C, s->english, s->math, s->sum);
}
void ArrayDisplayStudent(Student *s, int n) {
  for (int i = 0; i < n; ++i) {
    displayStudent(s + i);
  }
}
Student ArrayStudent[100];

int main() {
  double a, b, c;
  int idx = 0;
  while (scanf("%lf %lf %lf", &a, &b, &c) !=EOF) {
    Student s;
    initStudent(&s);
    s.C = a;
    s.english = b;
    s.math = c;
    countStudent(&s);
    ArrayStudent[idx++] = s;
  }
  sortStudent(ArrayStudent, idx);
  ArrayDisplayStudent(ArrayStudent, idx);
  return 0;
}

void initStudent(Student *s) {
  s->C = 0;
  s->english = 0;
  s->math = 0;
  s->sum = 0;
}
void countStudent(Student *s) {
  s->sum = s->C + s->english + s->math;
}
int cmp(const void *s1, const void *s2) {
  double delta = (((Student *) s1)->sum - ((Student *) s2)->sum);
  if (delta > 0) {
    return -1;
  } else if (delta == 0) {
    return 0;
  } else {
    return 1;
  }
}
void sortStudent(Student *s, int cnt) {
  qsort(s, cnt, sizeof *s, cmp);
}
