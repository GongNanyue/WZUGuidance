void initHeap(Heap H, ElementType data[], int n) {
  H->size = n;
  for (int i = 0; i <= n; ++i)
    H->data[i] = data[i];
  for (int i = n / 2; i >= 1; --i)
    heapify(H, i);
  for (int i = 0; i <= n; ++i)
    data[i] = H->data[i];
}
