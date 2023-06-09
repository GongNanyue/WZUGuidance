
struct edge {
    int a, b, w;

    bool operator<(const edge &other) const {
        return w < other.w;
    }
};


void addVertex(Graph g, VertexType v);

void addEdge(Graph g, VertexType v1, VertexType v2, int w);

int leader[MAXVEX];

int findleader(int u) {
    return leader[u] == u ? u : leader[u] = findleader(leader[u]);
}

int Kruskal(Graph g, Graph t) {//该函数用Kruskal算法求g的最小生成树t,并返回最小生成树的权。 如果最小生成树不存在，则返回-1。
    int sum = 0, cnt = 0;
    for (int i = 0; i < g->vertexNum; i++) leader[i] = i;
    vector<edge> es;
    for(int i = 0;i < g->vertexNum;++i)
        for(ENode *p = g->vexs[i].firstEdge;p != NULL;p = p->nextEdge)
            if(i < p->adjVertex)//每条边只会被添加一次
                es.push_back({i, p->adjVertex, p->weight});
    sort(es.begin(), es.end());
    for (int i = 0; i < es.size(); i++) {
        int u = es[i].a, v = es[i].b, w = es[i].w;
        int lu = findleader(u), lv = findleader(v);
        if (lu != lv) {
            leader[lu] = lv;
            addVertex(t, g->vexs[u].data);
            addVertex(t, g->vexs[v].data);
            addEdge(t, g->vexs[u].data, g->vexs[v].data, w);
            sum += w;
            cnt++;
        }
    }
    if (cnt < g->vertexNum - 1) return -1;
    return sum;



}
