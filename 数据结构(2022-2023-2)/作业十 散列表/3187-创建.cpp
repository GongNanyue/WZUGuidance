
HashTable *create(int size) {
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->lists = (List *) malloc(sizeof(List) * size);

    for (int i = 0; i < hashTable->size; ++i) {
        hashTable->lists[i] = (HashNode *) malloc(sizeof(HashNode));
    }
    return hashTable;
}
