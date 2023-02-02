
void destroyList(LinkList L) {
  Node *p = L,*q = L->next;
  free(L);
  while (q){
    p = q;
    q = q->next;
    free(p);
  }

}
