void insert(HashTable * h,ElementType key){
    int idx = find(h,key);
    if(h->cells[idx].key != key){
        h->cells[idx].key = key;
        h->cells[idx].flag = USED;
        h->size++;
    }
    if(h->size >= h->capacity/2)
        rehash(h);
}
