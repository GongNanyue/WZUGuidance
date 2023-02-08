
int push(SeqQueue *Q, ElementType x) {
  if (full(Q)) return 0;
  Q->array[Q->rear] = x;
  Q->rear = (Q->rear+1)% Q->capacity;
  ++Q->length;
  return 1;
}
