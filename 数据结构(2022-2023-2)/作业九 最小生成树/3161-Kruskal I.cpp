
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

int Kruskal(Graph g) {//该函数用Kruskal算法求g的最小生成树的权，并返回最小生成树的权。如果最小生成树不存在，则返回-1。
    int res = 0, cnt = 0;

    vector<Edge> es;
    for (int i = 0; i < g->vertexNum; ++i)
        for (ENode *p = g->vexs[i].firstEdge; p != NULL; p = p->nextEdge)
            es.push_back(Edge(i, p->adjVertex, p->weight));
    std::sort(es.begin(), es.end());

    for (int i = 0; i < g->vertexNum; ++i)
        leader[i] = i;

    for (int i = 0; i < es.size(); ++i) {
        int a = es[i].a, b = es[i].b, w = es[i].w;
        if (findleader(a) != findleader(b)) {
            res += w;
            cnt++;
            leader[findleader(a)] = findleader(b);
        }
    }
    if (cnt != g->vertexNum - 1)
        return -1;
    else
        return res;

}
