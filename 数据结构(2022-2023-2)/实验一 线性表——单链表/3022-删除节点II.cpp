
int delNode(LinkList L, int i, ElementType *px) {
  Node *p = L;
  --i;
  while (p->next && i) {
    p = p->next;
    --i;
  }
  if(!p->next)return 0;
  Node * q = p->next;
  p->next = q->next;
  *px = q->data;
  free(q);
  return 1;
}
