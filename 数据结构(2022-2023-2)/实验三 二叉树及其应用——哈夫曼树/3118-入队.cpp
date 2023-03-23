void push(Heap H, ElementType x) {
    H->data[++H->size] = x;
    int i = H->size;
    while (i >= 2 && *(H->data[i]) < *(H->data[parent(i)])){
        swap(H,i, parent(i));
        i = parent(i);
    }
        
}
