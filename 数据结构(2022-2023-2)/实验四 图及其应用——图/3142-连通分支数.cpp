int p[MAXVEX];


int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}

bool isConnect(int u, int v) {
    return find(u) == find(v);
}

void merge(int u, int v) {

    p[find(v)] = find(u);
}


int connectedComps(Graph g) {
    for (int i = 0; i < g->vertexNum; ++i)
        p[i] = i;
    for (int i = 0; i < g->vertexNum; ++i)
        for (int j = i + 1; j < g->vertexNum; ++j)
            if (g->edge[i][j] == 1)
                merge(i, j);
    int cnt = 0;
    for (int i = 0; i < g->vertexNum; ++i)
        if (p[i] == i)
            ++cnt;
    return cnt;
}
