int findSet(Set S, int x) {
    return S->parent[x] == -1 ? x : S->parent[x] = findSet(S, S->parent[x]);
}
