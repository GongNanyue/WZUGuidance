
void destroyStack(SeqStack *S) {
  free(S->array);
  free(S);
}
