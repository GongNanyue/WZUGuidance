
int distance(Graph g, VertexType v, VertexType u) {
    int a = locateVertex(g, v), b = locateVertex(g, u);

    memset(g->visited, false, sizeof g->visited);
    int dist[g->vertexNum];
    memset(dist, 0x3f, sizeof dist);
    dist[a] = 0;

    for (int i = 0; i < g->vertexNum; ++i) {
        int x = -1, minDis = 0x3f3f3f3f;
        for (int j = 0; j < g->vertexNum; ++j)
            if (g->visited[j] == 0 && dist[j] < minDis) {
                x = j;
                minDis = dist[j];
            }

        g->visited[x] = true;
        for (int j = 0; j < g->vertexNum; ++j)
            if (g->edge[x][j] == 1)
                if (dist[j] > dist[x] + g->edge[x][j])
                    dist[j] = dist[x] + g->edge[x][j];
    }
    if (dist[b] == 0x3f3f3f3f)
        return 0;
    else return dist[b];

}
