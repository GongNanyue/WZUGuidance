void destroy (HashTable * h){
    free(h->cells);
    free(h);
}
