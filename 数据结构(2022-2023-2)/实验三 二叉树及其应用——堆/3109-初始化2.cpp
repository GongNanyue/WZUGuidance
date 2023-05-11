void initHeap(Heap H, ElementType data[], int n) {
    H->size = n;
    memcpy(H->data, data, sizeof(ElementType) * (n + 1));
    sort(H->data + 1, H->data + H->size + 1, greater<ElementType>());
    //直接在[1,H->size]从大到小排序
    memcpy(data, H->data, sizeof(ElementType) * (n + 1));
    
}
