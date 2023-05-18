void DFS(Graph g, int i){
    g->vexs[i].visited = 1;
    for(ENode *p = g->vexs[i].firstEdge;p != NULL;p = p->nextEdge){
        if(!g->vexs[p->adjVertex].visited)
            DFS(g,p->adjVertex);
    }
}
