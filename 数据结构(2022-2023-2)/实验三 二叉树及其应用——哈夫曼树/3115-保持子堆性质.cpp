void heapify(Heap H, int i) {
  //也就是down()函数
  int smallest = i;
  if (left(i) <= H->size && *(H->data[left(i)]) < *(H->data[smallest]))
    //注意比较的是HNode, 不是HNode*
    smallest = left(i);
  if (right(i) <= H->size && *(H->data[right(i)]) < *(H->data[smallest]))
    smallest = right(i);
  if (smallest != i) {
    swap(H, i, smallest);
    heapify(H, smallest);
  }

}
