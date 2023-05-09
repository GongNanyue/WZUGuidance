
ENode *findEdge(Graph g, int i, int j) {
    for (ENode *p = g->vexs[i].firstEdge; p != NULL; p = p->nextEdge) {
        if (p->adjVertex == j) return p;
    }
    return NULL;
}
