void DFS(Graph g, int i){
    g->visited[i] = 1;
    for(int v = 0;v < g->vertexNum;++v)
        if(g->edge[i][v] == 1 && g->visited[v] == 0 )
            DFS(g,v);
}
