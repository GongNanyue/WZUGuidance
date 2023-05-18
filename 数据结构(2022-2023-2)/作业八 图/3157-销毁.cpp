
void destroyGraph(Graph g){
    if(g == NULL) return;
    for(int i = 0;i <g->vertexNum;++i){
        ENode *p = g->vexs[i].firstEdge;
        while (p!= NULL){
            ENode *q = p->nextEdge;
            free(p);
            p = q;
        }
        g->vexs[i].firstEdge = NULL;
    }
    free(g);
}
