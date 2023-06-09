
struct Edge {
    int a, b, w;

    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }

    bool operator==(const Edge &A) const {
        return (a == A.a && b == A.b && w == A.w) || (a == A.b && b == A.a && w == A.w);
    }

    bool operator<(const Edge &A) const {
        return w < A.w;
    }
};


int leader[MAXVEX];

int findleader(int u) {
    return leader[u] == u ? u : leader[u] = findleader(leader[u]);
}


int Kruskal(Graph g) {
    int sum = 0, cnt = 0;
    vector<Edge> edges;
    for (int i = 0; i < g->vertexNum; i++) {
        for (int j = i + 1; j < g->vertexNum; j++) {
            if (g->edge[i][j] != INT_MAX) {
                edges.push_back(Edge(i, j, g->edge[i][j]));
            }
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < g->vertexNum; i++) {
        leader[i] = i;
    }
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int la = findleader(a), lb = findleader(b);
        if (la != lb) {
            leader[la] = lb;
            sum += w;
            cnt++;
        }
        if (cnt == g->vertexNum - 1) {
            break;
        }
    }

    if (cnt != g->vertexNum - 1)
        return -1;
    else
        return sum;

}
