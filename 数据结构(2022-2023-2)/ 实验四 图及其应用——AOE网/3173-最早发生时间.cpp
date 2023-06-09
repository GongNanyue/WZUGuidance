int TopSort(AOENetwork g){
    //该函数把AOE网g中所有顶点(事件)按最早发生时间的拓扑排序顺序计算所有所有顶点(事件)的最早发生时间
    //如果g不存在回路返回1，否则返回0
    //已知点表中第一个点是源点，最后一个点是汇点
    int stack[MAXVEX];
    int top = -1;
    int count = 0;
    for(int i = 0; i < g->vertexNum; i++){
        if(g->vexs[i].inDegree == 0){
            stack[++top] = i;
        }
    }
    while(top != -1){
        int v = stack[top--];
        count++;
        ENode* p = g->vexs[v].firstEdge;
        while(p != NULL){
            int k = p->adjVertex;
            g->vexs[k].inDegree--;
            if(g->vexs[k].inDegree == 0){
                stack[++top] = k;
            }
            if(g->vexs[k].earliest < g->vexs[v].earliest + p->weight){
                g->vexs[k].earliest = g->vexs[v].earliest + p->weight;
            }
            p = p->nextEdge;
        }
    }
    if(count < g->vertexNum){
        return 0;
    }
    return 1;
    
}
// int TopSort/*Topological Sort*/(AOENetwork g) {
//     vector<int> l;
//     queue<int> q;
//     for (int i = 0; i < g->vertexNum; ++i)
//         if (g->vexs[i].inDegree == 0) {
//             q.push(i);
//             g->vexs[i].earliest = 0;
//         }
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         l.push_back(u);

//         for (ENode *p = g->vexs[u].firstEdge; p != NULL; p = p->nextEdge) {
//             int v = p->adjVertex;
//             g->vexs[v].inDegree--;
//             g->vexs[v].earliest = max(g->vexs[v].earliest, g->vexs[u].earliest + p->weight);
//             if (g->vexs[v].inDegree == 0)
//                 q.push(v);
//         }
//     }

//     if (l.size() == g->vertexNum)return 1;
//     else return 0;
// }
