HashTable * create(int capacity){
    HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->capacity = nextPrime(capacity);
    hashTable->size = 0;
    hashTable->cells = (Cell*) malloc(sizeof(Cell) * hashTable->capacity);
    return hashTable;
}
