
AOENetwork createGraph(){// 该函数创建一个空的AEO网并返回其指针。
    AOENetwork G = (AOENetwork)malloc(sizeof(struct AOENetworkStruct));
    G->edgeNum = 0;
    G->vertexNum = 0;
    for(int i = 0; i < MAXVEX; i++){
        G->vexs[i].data = 0;
        G->vexs[i].inDegree = 0;
        G->vexs[i].earliest = 0;
        G->vexs[i].latest = 0;
        G->vexs[i].firstEdge = NULL;
    }
    return G;
}
