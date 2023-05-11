void initHeap(Heap H, ElementType data[], int n) {
  //Heap H中的data 和 参数data都要堆化
  H->size = n;//更改H的数据大小
  for (int i = 0; i <= n; ++i)//i从1开始也可以
    H->data[i] = data[i];
  for (int i = n / 2; i >= 1; --i)
    heapify(H, i);
  for (int i = 0; i <= n; ++i)//i从1开始也可以
    data[i] = H->data[i];
}
