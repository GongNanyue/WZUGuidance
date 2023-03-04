void heapify(Heap H, int i) {
  int smallest = i;
  if (left(i) <= H->size && *H->data[left(i)] < *H->data[smallest])
    smallest = left(i);
  if (right(i) <= H->size && *H->data[right(i)] < *H->data[smallest])
    smallest = right(i);
  if (smallest != i) {
    swap(H, i, smallest);
    heapify(H, smallest);
  }

}
