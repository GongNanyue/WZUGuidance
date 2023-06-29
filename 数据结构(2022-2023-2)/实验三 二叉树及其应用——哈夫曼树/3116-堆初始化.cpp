void initHeap(Heap H, Node data[], int n) {
/*
  H->data = (ElementType *) malloc(sizeof(ElementType) * (n + 1));
  H->capacity = n;
  H->size = n;
  在createHeap 创建 H的时候就已经分配好内存了 所以上面可以不写*/
  for (int i = 1; i <= n; ++i) {
    H->data[i] = (HTNode*) malloc(sizeof(HTNode));//H->data中只存放指针 但是还没有真正的HTNode可以指向
    H->data[i]->weight = data[i].weight;
    H->data[i]->value = data[i].value;
    H->data[i]->lchild = H->data[i]->rchild = NULL;
    H->data[i]->depth  = 0;

  }

  for (int i = H->size / 2; i >= 1; --i)
    heapify(H, i);
}
