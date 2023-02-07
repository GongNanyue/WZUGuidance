
LinkStack createStack() {
  LinkStack ls = (Node *) malloc(sizeof( Node));
  ls->next = NULL;
  return ls;
}
