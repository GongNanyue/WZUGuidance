
void clearList(LinkList L) {
  Node *p = L, *q = L->next;
  while (q) {
    p = q;
    q = q->next;
    free(p);
  }
  L->next = NULL;
}
