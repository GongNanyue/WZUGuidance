void destroyList(SeqList *L){
  free(L->array);
  free(L);
}
