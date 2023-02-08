
Node *find(LinkList L, ElementType x) {
  Node *p = L->next;
  while (p && p->data != x)
    p = p->next;
  return p;
}
