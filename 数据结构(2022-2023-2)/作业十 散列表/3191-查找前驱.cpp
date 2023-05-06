

HashNode *findPre(HashTable *h, ElementType key) {
    int idx = hash(h, key);
    HashNode *p = h->lists[idx], *q = h->lists[idx]->next;
    while (q != NULL && q->key != key) {
        p = q;
        q = q->next;
    }
    if(q == NULL)return NULL;
    else return p;

}
