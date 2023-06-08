
int dfs(AOENetwork g,int idx){
    int cnt = 0;
    if(idx == g->vertexNum - 1)return 1;
    
    for(ENode *p = g->vexs[idx].firstEdge;p != NULL;p = p->nextEdge){
        int v = p->adjVertex;
        if(p->earliest == p->latest){
            cnt += dfs(g,v);
        }
    }
    return cnt;
}


int pathNum(AOENetwork g) {
    return dfs(g,0);
}
