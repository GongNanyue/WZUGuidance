int pop(SeqStack *S) {
  if (S->top == -1)return 0;
  --S->top;
  return 1;
}
