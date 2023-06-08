

vector<int>  myTopSort/*Topological Sort*/(AOENetwork g) {
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

    if (l.size() == g->vertexNum)return l;
    else return {};
}




void event(AOENetwork g) {//函数计算AOE网g中所有顶点(事件)的最早与最迟发生时间。已知点表中第一个点是源点，最后一个点是汇点。
    vector<int> l = myTopSort(g);

    for(int i = 0;i < g->vertexNum;++i)
        g->vexs[i].latest = g->vexs[g->vertexNum - 1].earliest;

    for(int i = l.size()-1;i >= 0;--i){
        int u = l[i];
        for(ENode *p = g->vexs[u].firstEdge;p != NULL;p = p->nextEdge){
            int v = p->adjVertex;
            g->vexs[u].latest = min(g->vexs[u].latest,g->vexs[v].latest - p->weight);
        }
    }

}
