
Node *findPrevious(LinkList L, ElementType x) {
  Node *p = L;
  while (p->next && p->next->data != x) {
    p = p->next;
  }
  return p;
}
int delNode1(LinkList L, ElementType x) {
  Node *p = findPrevious(L, x), *q = p->next;
  if (!q)return 0;
  p->next = q->next;
  free(q);
  return 1;
}
