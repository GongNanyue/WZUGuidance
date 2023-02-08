
void printList(LinkList L) {
  Node *p = L->next;
  while (p) {
      printf("%d ",p->data);
    p = p->next;
  }
puts("");
}
