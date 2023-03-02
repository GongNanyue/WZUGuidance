int pop(LinkQueue *Q){
  if(empty(Q))return 0;
  if(Q->front == Q->rear){
    free(Q->front);
    Q->front = Q->rear = NULL;
    return 1;
  }
  QNode *np = Q->front;
  Q->front = Q->front->next;
  free(np);
  return 1;
}
