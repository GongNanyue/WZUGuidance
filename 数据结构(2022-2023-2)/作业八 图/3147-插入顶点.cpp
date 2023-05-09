
void addVertex(Graph g, VertexType v) {
    if(locateVertex(g,v) != -1)return;

    g->vexs[g->vertexNum].data = v;
    g->vexs[g->vertexNum].visited = false;
    g->vexs[g->vertexNum].firstEdge = NULL;
    g->vertexNum++;
    
}
