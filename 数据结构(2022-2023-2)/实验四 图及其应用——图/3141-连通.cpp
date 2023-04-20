int connect(Graph g, VertexType v, VertexType u) {
    memset(g->visited,0,sizeof g->visited);
    int i = locateVertex(g,v),j = locateVertex(g,u);
    BFS(g,i);
    return g->visited[j];
    
}
