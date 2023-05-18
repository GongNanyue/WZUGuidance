int hash(HashTable * h,ElementType key){
    return key % h->capacity;
}
