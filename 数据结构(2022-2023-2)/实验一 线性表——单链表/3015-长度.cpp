
int getLength(LinkList L) {
  int cnt = 0;
  Node *p = L->next;
  while (p) {
    ++cnt;
    p = p->next;
  }
  return cnt;
}
