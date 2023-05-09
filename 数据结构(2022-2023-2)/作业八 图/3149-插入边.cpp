
void addEdge(Graph g, VertexType v1, VertexType v2, int w) {
    int i = locateVertex(g, v1), j = locateVertex(g, v2);
    if (i == -1 || j == -1) return;

    ENode *eNode = findEdge(g, i, j);
    if (eNode != NULL) {
        eNode->weight = min(eNode->weight, w);
        return;
    }


    ENode *ieNode = (ENode *) malloc(sizeof(ENode));
    ieNode->weight = w;
    ieNode->adjVertex = j;
    ieNode->nextEdge = g->vexs[i].firstEdge;
    g->vexs[i].firstEdge = ieNode;

    ENode *jeNode = (ENode *) malloc(sizeof(ENode));
    jeNode->weight = w;
    jeNode->adjVertex = i;
    jeNode->nextEdge = g->vexs[j].firstEdge;
    g->vexs[j].firstEdge = jeNode;
    
    g->edgeNum++;

}
