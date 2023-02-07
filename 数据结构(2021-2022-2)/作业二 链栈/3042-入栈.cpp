int push(LinkStack S, ElementType x) {
  Node *np = (Node *) malloc(sizeof(Node));
  if (!np)return 0;
  np->data = x;
  np->next = S->next;
  S ->next = np;

  return 1;
}
