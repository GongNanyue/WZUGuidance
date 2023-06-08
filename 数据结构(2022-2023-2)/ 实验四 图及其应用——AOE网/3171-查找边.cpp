ENode *findEdge(AOENetwork g, int i, int j) {
    ENode *p = g->vexs[i].firstEdge;
    while (p != NULL && p->adjVertex != j)
        p = p->nextEdge;
    return p;

}
