
void clearStack(LinkStack S) {
  Node *p = S, *q = S->next;
  S->next = NULL;
  while (q) {
    p = q;
    q = q->next;
    free(p);
  }
}
