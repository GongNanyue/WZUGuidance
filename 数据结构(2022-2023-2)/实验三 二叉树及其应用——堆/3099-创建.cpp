Heap createHeap(int capacity) {
  Heap heap = (Heap) malloc(sizeof(HNode));
  //第0个数据不使用
  heap->data = (ElementType *) malloc(sizeof(ElementType) * (capacity + 1));
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}
