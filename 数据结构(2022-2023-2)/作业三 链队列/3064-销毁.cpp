void destroyQueue(LinkQueue *Q){
  if (Q->front == NULL && Q->rear == NULL)return;
  QNode *p0 = Q->front, *p1 = Q->front->next;
  while (p1 != NULL) {
    free(p0);
    p0 = p1;
    p1 = p1->next;
  }
  free(p0);
  Q->front = Q->rear = NULL;
  free(Q);
}
