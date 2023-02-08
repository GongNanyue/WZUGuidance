PolyList createList() {
  PolyList pl = (PolyList) malloc(sizeof(PolyNode));
  pl->next = NULL;
  return pl;
}
