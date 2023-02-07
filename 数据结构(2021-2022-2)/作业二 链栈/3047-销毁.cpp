
void destroyStack(LinkStack S) {
  Node *p = S,*q = S->next;
  free(S);
  while (q){
    p = q;
    q = q->next;
    free(p);
  }
}
