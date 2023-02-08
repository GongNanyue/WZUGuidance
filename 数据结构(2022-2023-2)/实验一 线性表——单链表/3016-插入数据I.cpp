
void insertHead(LinkList L, ElementType x) {
  Node *p = (Node *) malloc(sizeof(Node));
  p->data = x;
  p->next = L->next;
  L->next = p;
}
