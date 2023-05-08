void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX])
{
    //初始化D和P数组
    for (int i = 0; i < g->vertexNum; i++)
    {
        for (int j = 0; j < g->vertexNum; j++)
        {
            if (i == j) //对角线元素为0
            {
                D[i][j] = 0;
                P[i][j] = i;
            }
            else //非对角线元素为无穷大
            {
                D[i][j] = INT_MAX;
                P[i][j] = -1;
            }
        }
    }

    //根据图的邻接表更新D和P数组
    for (int i = 0; i < g->vertexNum; i++)
    {
        ENode *p = g->vexs[i].firstEdge; //指向第i个顶点的第一条边
        while (p != NULL) //遍历所有与i相邻的顶点
        {
            int j = p->adjVertex; //取出边的另一端顶点编号
            int w = p->weight; //取出边的权值
            D[i][j] = w; //更新i到j的最短距离为w
            P[i][j] = i; //更新i到j的最短路径上的前驱为i
            p = p->nextEdge; //指向下一条边
        }
    }

    //使用Floyd算法更新D和P数组
    for (int k = 0; k < g->vertexNum; k++) //遍历所有中间顶点
    {
        for (int i = 0; i < g->vertexNum; i++) //遍历所有起点
        {
            for (int j = 0; j < g->vertexNum; j++) //遍历所有终点
            {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][k] + D[k][j] < D[i][j]) //如果通过k可以缩短i到j的距离
                {
                    D[i][j] = D[i][k] + D[k][j]; //更新i到j的最短距离为i到k加上k到j的距离
                    P[i][j] = P[k][j]; //更新i到j的最短路径上的前驱为k到j的前驱
                }
            }
        }
    }
}
