void BFS(Graph g, int i) {
    queue<int> q;
    q.push(i);
    g->visited[i] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < g->vertexNum; ++v)
            if (g->edge[u][v] == 1 && g->visited[v] != 0) {
                q.push(v);
                g->visited[v] = 1;
            }
    }

}
