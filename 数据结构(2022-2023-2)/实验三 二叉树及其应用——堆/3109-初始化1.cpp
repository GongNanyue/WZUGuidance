void initHeap(Heap H, ElementType data[], int n) {
    H->size = n;
    memcpy(H->data + 1, data + 1, sizeof(ElementType) * n);
    //memcpy复制大小是字节个数
    //从data[1] 到 data[n] 有n个
    //也可以写成memcpy(H->data , data , sizeof(ElementType) * (n+ 1));
    for (int i = n / 2; i >= 1; --i)
        heapify(H, i);
    memcpy(data + 1, H->data + 1, sizeof(ElementType) * n);
    //data也要变成堆形式
}
