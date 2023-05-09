
int degree(Graph g, VertexType v) {
    int i = locateVertex(g, v);
    if (i == -1)return 0;

    int cnt = 0;
    for (ENode *eNode = g->vexs[i].firstEdge; eNode != NULL; eNode = eNode->nextEdge) 
        ++cnt;
    return cnt;
}
