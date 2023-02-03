
void destroyQueue(SeqQueue *Q) {
  free(Q->array);
  free(Q);
}
