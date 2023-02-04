
void insertTail(PolyList L, int coef, int exp) {
  PolyNode *nd = L;
  while (nd->next)
    nd = nd->next;
  PolyNode *newNd = (PolyNode *) malloc(sizeof(PolyNode));
  newNd->coef = coef;
  newNd->exp = exp;
  newNd->next = nd->next;
  nd->next = newNd;
}
