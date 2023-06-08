void addVertex(AOENetwork g, VertexType v){//该函数在AEO网g中增加顶点v(在点表最后增加，在点表中编号从0开始)，如果顶点已经存在则什么都不做。
    int idx = locateVertex(g,v);
    if(idx != -1)return;

    g->vexs[g->vertexNum].data = v;
    g->vexs[g->vertexNum].inDegree = 0;
    g->vexs[g->vertexNum].earliest = -1;
    g->vexs[g->vertexNum].latest = -1;
    g->vexs[g->vertexNum].firstEdge = NULL;
    g->vertexNum++;
}
