void delVertex(Graph g, VertexType v) {
    int u = locateVertex(g, v);
    if (u == -1)return;

    for (int i = 0; i < g->vertexNum; ++i)
        delEdge(g, v, g->vexs[i]);

    for (int i = u; i < g->vertexNum - 1; ++i)
        g->vexs[i] = g->vexs[i + 1];

    for (int i = u; i < g->vertexNum - 1; ++i)
        for (int j = 0; j < u; ++j)
            g->edge[i][j] = g->edge[i + 1][j];
    
    for(int j = u;j < g->vertexNum-1;++j)
        for(int i = 0;i < u;++i)
            g->edge[i][j] = g->edge[i][j+1];
    
    for(int i = u;i < g->vertexNum-1;++i)
        for(int j = u;j < g->vertexNum-1;++j)
            g->edge[i][j] = g->edge[i+1][j+1];
    
    g->vertexNum--;


}
