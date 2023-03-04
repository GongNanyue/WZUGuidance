void destroyHeap(Heap H) {
  free(H->data);
  free(H);
  H = NULL;
}
