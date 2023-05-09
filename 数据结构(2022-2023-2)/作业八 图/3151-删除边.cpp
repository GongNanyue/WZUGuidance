void delEdge(Graph g, VertexType x, VertexType y) {
    //首先找到x和y对应的顶点编号
    int i = locateVertex(g, x);
    int j = locateVertex(g, y);
    //如果顶点编号不存在，或者边不存在，直接返回
    if (i == -1 || j == -1) return;
    ENode *p = findEdge(g, i, j);
    if (p == NULL) return;
    //否则，删除边ij，并更新边数
    ENode *q = g->vexs[i].firstEdge;
    if (q == p) { //如果p是第一条边，直接删除
        g->vexs[i].firstEdge = p->nextEdge;
        free(p);
    } else { //否则，找到p的前驱节点，然后删除
        while (q->nextEdge != p) {
            q = q->nextEdge;
        }
        q->nextEdge = p->nextEdge;
        free(p);
    }
    //同理，删除边ji
    p = findEdge(g, j, i);
    q = g->vexs[j].firstEdge;
    if (q == p) {
        g->vexs[j].firstEdge = p->nextEdge;
        free(p);
    } else {
        while (q->nextEdge != p) {
            q = q->nextEdge;
        }
        q->nextEdge = p->nextEdge;
        free(p);
    }
    //最后，更新边数
    g->edgeNum--;
}
