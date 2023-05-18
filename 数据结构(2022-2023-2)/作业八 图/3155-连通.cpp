
int connect(Graph g, VertexType x, VertexType y){
    BFS(g, locateVertex(g,x));
    return g->vexs[locateVertex(g,y)].visited;
}
