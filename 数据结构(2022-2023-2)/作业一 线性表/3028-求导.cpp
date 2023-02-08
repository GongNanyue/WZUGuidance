
void destroyPolyList(PolyList L) {
  PolyNode *p = L, *q = L->next;
  free(L);
  while (q) {
    p = q;
    q = q->next;
    free(p);
  }
}
void clearPolyList(PolyList L) {
  PolyNode *p = L, *q = L->next;
  while (q) {
    p = q;
    q = q->next;
    free(p);
  }
  L->next = NULL;
}
void derivative(PolyList L) {
  PolyList new_list = createList();
  for (PolyNode *np = L->next; np; np = np->next) {
    if (np->exp) {
      insertTail(new_list, np->coef * np->exp, np->exp - 1);
    } else break;
  }
  clearPolyList(L);
  for (PolyNode *np = new_list->next; np; np = np->next) {
    insertTail(L, np->coef, np->exp);
  }
  destroyPolyList(new_list);
}
