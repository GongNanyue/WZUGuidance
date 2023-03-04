int push(Heap H, ElementType x) {
  if (full(H))return 0;
  ++H->size;
  H->data[H->size] = x;
  initHeap(H,H->data,H->size);
  return 1;
}
