
int push(SeqStack *S, ElementType x) {
  if (S->top + 1 == S->capacity)
    return 0;
  S->array[++S->top] = x;
  return 1;
}
