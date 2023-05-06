
void del(HashTable *h, ElementType key) {
    HashNode *pre = findPre(h, key);
    if (pre != NULL) {
        HashNode *q = pre->next->next;
        free(pre->next);
        pre->next = q;
    }
}
