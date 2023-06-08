
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w) {
    //该函数在AOE网g中增加一条从v1到v2权为w的边，如果已经有边则保留权最小的边。如果点v1或者v2不存在，则什么都不做。
    int i = locateVertex(g, v1), j = locateVertex(g, v2);
    if (i == -1 || j == -1)return;
    ENode *eNode = findEdge(g, i, j);
    if (eNode == NULL) {// 没有边
        ENode *eNode1 = new ENode;
        eNode1->weight = w;
        //eNode1->latest = eNode1->earliest = -1;
        eNode1->adjVertex = j;

        eNode1->nextEdge = g->vexs[i].firstEdge;
        g->vexs[i].firstEdge = eNode1;

        g->edgeNum++;
        ++g->vexs[j].inDegree;
    } else {
        eNode->weight = min(eNode->weight, w);
    }
}
