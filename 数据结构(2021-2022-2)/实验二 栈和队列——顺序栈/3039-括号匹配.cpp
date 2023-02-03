#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char ElementType;
typedef struct {
  ElementType *array; //存放栈数据
  int top;            //栈顶
  int capacity;        //容量
} SeqStack;

void clearStack(SeqStack *S) {
  S->top = -1;
}

ElementType top(SeqStack *S) {
  return S->array[S->top];
}

int pop(SeqStack *S) {
  if (S->top == -1)return 0;
  --S->top;
  return 1;
}

int empty(SeqStack *S) {
  return S->top == -1;
}
int push(SeqStack *S, ElementType x) {
  if (S->top + 1 == S->capacity)
    return 0;
  S->array[++S->top] = x;
  return 1;
}
int full(SeqStack *S) {
  return S->top + 1 == S->capacity;
}
SeqStack *createStack(int capacity) {
  SeqStack *stk = (SeqStack *) malloc(sizeof(SeqStack));
  stk->capacity = capacity;
  stk->top = -1;
  stk->array = (ElementType *) malloc(capacity * sizeof(ElementType));
  return stk;
}
void destroyStack(SeqStack *S) {
  free(S->array);
  free(S);
}
char s[1010];
int main() {

  scanf("%s", s);
  SeqStack *stk = createStack(1010);
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      push(stk, s[i]);
    } else if (!(top(stk) == '(' && s[i] == ')' ||
               top(stk) == '[' && s[i] == ']' ||
               top(stk) == '{' && s[i] == '}')) {
      puts("no");
      return 0;
    } else{
      pop(stk);
    }
  }
  if (empty(stk))
    puts("yes");
  else
    puts("no");

  return 0;
}
