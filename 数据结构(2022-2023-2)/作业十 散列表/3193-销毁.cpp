
void destroy(HashTable *h) {
    for (int i = 0; i < h->size; ++i) {
        HashNode *p = h->lists[i], *q = p->next;
        while (q != NULL){
            free(p);
            p = q;
            q = q->next;
        }
        free(p);
    }
    free(h->lists);
    free(h);

}
