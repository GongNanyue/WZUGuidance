int connectedComps(Graph g){
    int cnt = 0;
    for(int i = 0;i < g->vertexNum;++i){
        if(!g->vexs[i].visited){
            BFS(g,i);
            ++cnt;
        }
    }
    return cnt;
}
