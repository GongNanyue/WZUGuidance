
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]) {
    for (int i = 0; i < g->vertexNum; ++i)
        for (int j = 0; j < g->vertexNum; ++j)
            if (i == j) {
                D[i][j] = 0;
                P[i][j] = i;
            } else {
                D[i][j] = INT_MAX;
                P[i][j] = -1;
            }


    for (int i = 0; i <g->vertexNum; ++i)
        for (int j = 0; j <g->vertexNum; ++j)
        {
            D[i][j] = min(D[i][j],g->edge[i][j]);
            P[i][j] = i;
        }


    for (int k = 0; k < g->vertexNum; ++k)
        for (int i = 0; i < g->vertexNum; ++i)
            for (int j = 0; j < g->vertexNum; ++j)
                if (D[i][j] > D[i][k] + D[k][j] && D[i][k] != INT_MAX && D[k][j] != INT_MAX){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }


}
