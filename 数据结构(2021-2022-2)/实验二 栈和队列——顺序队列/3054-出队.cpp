
int pop(SeqQueue *Q, ElementType *x) {
  if(empty(Q))return 0;
  *x = Q->array[Q->front];
  Q->front =(Q->front + 1) % Q->capacity;
  --Q->length;
  return 1;
}
