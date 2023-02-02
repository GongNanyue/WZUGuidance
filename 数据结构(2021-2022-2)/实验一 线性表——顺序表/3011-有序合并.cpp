
void mergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
  int i = 0, j = 0, k = 0;
  for (; i < LA->length && j < LB->length;) {
    if (LA->array[i] < LB->array[j])
      LC->array[k++] = LA->array[i++];
    else
      LC->array[k++] = LB->array[j++];
  }
  if (i == LA->length)
    memcpy(&LC->array[k], &LB->array[j], sizeof(int) * (LB->length - j));
  else
    memcpy(&LC->array[k], &LA->array[i], sizeof(int) * (LA->length - i));
  LC->length = LA->length+LB->length;
}
