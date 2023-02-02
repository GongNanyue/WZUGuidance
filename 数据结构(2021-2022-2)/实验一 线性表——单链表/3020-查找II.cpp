
Node* locate(LinkList L, int i){
  Node *p = L;
  while (p && i){
    p = p->next;
    --i;
  }
  if(p == L)return NULL;
  return p;
}
