void insert(HashTable *h, ElementType key) {
    if (find(h, key) == NULL){
        int idx = hash(h, key);
        HashNode *node = (HashNode*) malloc( sizeof (HashNode)) ;
        node->key = key;
        node->next = h->lists[idx]->next;
        h->lists[idx]->next = node;
    }
}
