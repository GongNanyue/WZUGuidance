
SeqStack *createStack(int capacity) {
  SeqStack *stk = (SeqStack *) malloc(sizeof(SeqStack));
  stk->capacity = capacity;
  stk->top = -1;
  stk->array = (ElementType *) malloc(capacity * sizeof(ElementType));
  return stk;
}
