int push(LinkQueue *Q, ElementType x) {
  QNode *q_node = (QNode *) malloc(sizeof(QNode));
  if (q_node == NULL)return 0;
  q_node->data = x;
  q_node->next = NULL;
  if (Q->front == Q->rear  && Q->rear ==  NULL) {
    //front 和 rear 指向NULL表示空
    Q->front = Q->rear = q_node;
  } else {
    Q->rear->next = q_node;
    Q->rear = q_node;
  }
  return 1;
}
