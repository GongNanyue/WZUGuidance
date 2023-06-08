int active(AOENetwork g) {
    int cnt = 0;

    for(int i = 0;i < g->vertexNum;++i)
        for(ENode *p = g->vexs[i].firstEdge;p != NULL;p = p->nextEdge)
            p->latest = g->vexs[p->adjVertex].latest - p->weight;
    
    for (int i = 0; i < g->vertexNum; ++i) {
        for (ENode *p = g->vexs[i].firstEdge; p != NULL; p = p->nextEdge) {
            p->earliest = g->vexs[i].earliest;
            p->latest = min(p->latest, g->vexs[p->adjVertex].latest - p->weight);
            if (p->earliest == p->latest)
                cnt++;

        }
    }

    return cnt;
}
