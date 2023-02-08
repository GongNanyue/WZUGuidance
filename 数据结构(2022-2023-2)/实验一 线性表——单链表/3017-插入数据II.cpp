void insertTail(LinkList L, ElementType x) {
  Node *p = L;
  while (p->next)
    p = p->next;
  Node *q = (Node *) malloc(sizeof(Node));
  q->data = x;
  q->next = p->next;
  p->next = q;
}
