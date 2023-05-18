void insert(HashTable * h,ElementType key){
    int idx = find(h,key);
    h->cells[idx].key = key;
    h->cells[idx].flag = USED;
}
