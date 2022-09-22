
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const int subjectCnt = 3;

typedef struct Student_ {
  char id[10];
  char name[100];
  char sex;
  int year;
  int month;
  int day;
  int x;
  int y;
  int z;
  double average;
  double sum;
} Student;

void initStudent(Student *s);
void insertStudent(Student *s, char *id, char *name, const char *sex,
                   int year, int month, int day, int x, int y, int z);
void countStudent(Student *s);
void display(Student *s);

int main() {
  char op[10];
  while (scanf("%s", op) && (op[0] != 'Q' && op[0] != 'E')) {
    Student student;
    initStudent(&student);
    scanf("%s %s %c %d %d %d %d %d %d",
          student.id,
          student.name,
          &student.sex,
          &student.year,
          &student.month,
          &student.day,
          &student.x,
          &student.y,
          &student.z);
    countStudent(&student);
    display(&student);
  }
  printf("Good bye!\n");
  return 0;
}

void initStudent(Student *s) {
  memset(s->id, '\0', sizeof s->id);
  memset(s->name, '\0', sizeof s->name);
  s->sex = '\0';
  s->year = 0;
  s->month = 0;
  s->day = 0;
  s->x = 0;
  s->y = 0;
  s->z = 0;
  s->average = 0.0;
  s->sum = 0.0;
}

void insertStudent(Student *s, char *id, char *name, const char *sex,
                   int year, int month, int day, int x, int y, int z) {
  strcpy(s->id, id);
  strcpy(s->name, name);
  s->sex = *sex;
  s->year = year;
  s->month = month;
  s->day = day;
  s->x = x;
  s->y = y;
  s->z = z;
}
void countStudent(Student *s) {
  s->sum = s->x + s->y + s->z;
  s->average = s->sum / subjectCnt;
}

void display(Student *s) {
  printf("Insert:\n");
  printf("%s %s %c %d %d %d %.1lf %.1lf %.1lf %.1lf %.1lf\n", \
         s->id, s->name, s->sex, s->year, s->month, s->day, (double )s->x,(double ) s->y,(double ) s->z, s->average, s->sum);
}

