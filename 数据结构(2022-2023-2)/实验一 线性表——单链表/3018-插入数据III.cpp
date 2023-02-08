
int insertList(LinkList L, int i, ElementType x) {
  Node *p = L;
  --i;
  while (p->next && i) {
    p = p->next;
    --i;
  }
  if (i) return 0;
  Node *q = (Node *) malloc(sizeof(Node));
  q->data = x;
  q->next = p->next;
  p->next = q;
  return 1;
}
