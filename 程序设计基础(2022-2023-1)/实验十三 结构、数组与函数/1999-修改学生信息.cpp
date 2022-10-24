#include <bits/stdc++.h>
using namespace std;
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
void readStudent(Student *s);
void insertStudent(Student *s);
void countStudent(Student *s);
void display(Student *s);
void listDisplay(Student *s, int n);
int findStudent(char *id);
int  changeStudent(Student *s);



Student ArrayStudent[100];
int cnt = 0;//存放数目 当前可用

int main() {
  char op[10];

  while(scanf("%s", op) && (strcmp(op, "Quit") != 0 && strcmp(op, "Exit") != 0)){
    if(!strcmp(op, "Insert")){
      printf("Insert:\n");
      Student student;
      initStudent(&student);
      readStudent(&student);
      if(findStudent(student.id)==-1){
        countStudent(&student);
        display(&student);
        insertStudent(&student);
      }else{
        printf("Failed\n");
      }

    }else if(!strcmp(op, "List")){
      printf("List:\n");
      listDisplay(ArrayStudent, cnt);
    }else if(!strcmp(op, "Find")){
      printf("Find:\n");
      char id[10];
      scanf("%s", id);
      int res = findStudent(id);
      if(res != -1){
        display(&(ArrayStudent[res]));
      }else{
        printf("Failed\n");
      }
    }else if(!strcmp(op,"Change")){
      printf("Change:\n");
      Student student;
      initStudent(&student);
      readStudent(&student);countStudent(&student);
      if(changeStudent(&student)==0){
        display(&student);
      }else{
        printf("Failed\n");
      }


    }
  }
  printf("Good bye!\n");
  return 0;
}

void readStudent(Student *s) {
  scanf("%s %s %c %d %d %d %d %d %d", s->id, s->name, &s->sex, &s->year, &s->month, &s->day, &s->x, &s->y, &s->z);
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

void insertStudent(Student *s) {
  ArrayStudent[cnt++] = *s;
}

void countStudent(Student *s) {
  s->sum = s->x+s->y+s->z;
  s->average = s->sum/subjectCnt;
}

void display(Student *s) {
  printf("%s %s %c %d %d %d %.1lf %.1lf %.1lf %.1lf %.1lf\n", \

         s->id,
         s->name,
         s->sex,
         s->year,
         s->month,
         s->day,
         (double) s->x,
         (double) s->y,
         (double) s->z,
         s->average,
         s->sum);
}

void listDisplay(Student *s, int n) {

  for(int i = 0; i<n; ++i){
    display(s+i);
  }
}

int findStudent(char *id) {
  //找到返回对应数组的下标，找不到返回-1
  for(int i = 0; i<cnt; ++i){
    if(!strcmp(ArrayStudent[i].id, id)){
      return i;
    }
  }
  return -1;
}
int changeStudent(Student *s) {
  int idx = findStudent(s->id);
  if(idx == -1){
    return -1;
  }else{
    ArrayStudent[idx].x = s->x;
    ArrayStudent[idx].y = s->y  ;
    ArrayStudent[idx].z  = s->z;
    strcpy(ArrayStudent[idx].name,s->name);
    ArrayStudent[idx].day = s->day;
    ArrayStudent[idx].month = s->month  ;
    ArrayStudent[idx].year = s->year;
    ArrayStudent[idx].sum = s->sum;
    ArrayStudent[idx].average = s->average;
    ArrayStudent[idx].sex = s->sex;
    return 0;
  }

}
