void unionSet(Set S, int x, int y) {
    int rootX = findSet(S, x);
    int rootY = findSet(S, y);
    if (rootX == rootY)
        return;
     S->parent[rootX] = rootY; 
    
}
