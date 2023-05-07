void destroySet(Set S) {
    free(S->parent);
    free(S);
}
