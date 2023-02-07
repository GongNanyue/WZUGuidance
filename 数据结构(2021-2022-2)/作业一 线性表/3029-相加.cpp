
void polyAdd(PolyList LA, PolyList LB, PolyList LC) {
  PolyNode *pa = LA->next, *pb = LB->next;
  while (pa && pb) {
    if (pa->exp > pb->exp) {
      insertTail(LC, pa->coef, pa->exp);
      pa = pa->next;
    } else if (pa->exp < pb->exp) {
      insertTail(LC, pb->coef, pb->exp);
      pb = pb->next;
    } else {
      if (pa->coef + pb->coef)
        insertTail(LC, pa->coef + pb->coef, pa->exp);
      pa = pa->next;
      pb = pb->next;

    }

  }
  while (pa) {
    insertTail(LC, pa->coef, pa->exp);
    pa = pa->next;
  }
  while (pb) {
    insertTail(LC, pb->coef, pb->exp);
    pb = pb->next;
  }
}
