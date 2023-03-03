Heap createHeap(int capacity) {
  Heap heap = (Heap) malloc(sizeof(HNode));
  heap->data = (ElementType *) malloc(sizeof(ElementType) * (capacity + 1));
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}
