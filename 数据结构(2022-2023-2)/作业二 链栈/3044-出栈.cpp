
int pop(LinkStack S) {
  if (empty(S))return 0;
  Node *np = S->next;
  S->next = np->next;
  free(np);

  return 1;
}
