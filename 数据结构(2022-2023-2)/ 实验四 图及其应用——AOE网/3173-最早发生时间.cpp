
int TopSort/*Topological Sort*/(AOENetwork g) {
    vector<int> l;
    queue<int> q;
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->vexs[i].inDegree == 0) {
            q.push(i);
            g->vexs[i].earliest = 0;
        }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        l.push_back(u);

        for (ENode *p = g->vexs[u].firstEdge; p != NULL; p = p->nextEdge) {
            int v = p->adjVertex;
            g->vexs[v].inDegree--;
            g->vexs[v].earliest = max(g->vexs[v].earliest, g->vexs[u].earliest + p->weight);
            if (g->vexs[v].inDegree == 0)
                q.push(v);
        }
    }

    if (l.size() == g->vertexNum)return 1;
    else return 0;
}
