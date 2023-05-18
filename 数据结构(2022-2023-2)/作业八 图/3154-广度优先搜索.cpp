
void BFS(Graph g, int i){
    g->vexs[i].visited = 1;
    queue<VNode> q;
    q.push(g->vexs[i]);

    while (!q.empty()){
        VNode hd = q.front();
        q.pop();
        
        for(ENode *p = hd.firstEdge;p != NULL;p = p->nextEdge){
            if(!g->vexs[p->adjVertex].visited){
                g->vexs[p->adjVertex].visited = 1;
                q.push(g->vexs[p->adjVertex]);
            }
        }
    }
}

