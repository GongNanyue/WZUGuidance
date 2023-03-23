
HuffmanTree createHuffmanTree(Node data[], int n) {

    Heap heap = createHeap(n);
    initHeap(heap, data, n);
    while (heap->size > 1) {
        HuffmanTree a = front(heap);
        pop(heap);
        HuffmanTree b = front(heap);
        pop(heap);
        HTNode *nodePointer = (HTNode *) malloc(sizeof(HTNode));
        nodePointer->value = std::min(a->value,b->value);
        nodePointer->weight = a->weight + b->weight;
        nodePointer->depth = std::max(a->depth, b->depth) + 1;
        nodePointer->lchild = a;
        nodePointer->rchild = b;
        push(heap,nodePointer);
    }
    return front(heap);
}
