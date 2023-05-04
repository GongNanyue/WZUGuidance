
HashNode *find(HashTable *h, ElementType key) {
    int idx = hash(h, key);
    HashNode *p = h->lists[idx]->next;

    while (p != NULL && p->key != key)
        p = p->next;
    return p;


}
