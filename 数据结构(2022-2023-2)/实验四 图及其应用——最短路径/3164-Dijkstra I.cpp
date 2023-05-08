void Dijkstra(Graph g, int s, int D[], int P[])
{
    //初始化D和P数组
    for (int i = 0; i < g->vertexNum; i++)
    {
        D[i] = INT_MAX; //假设所有顶点都不可达
        P[i] = -1; //假设所有顶点都没有前驱
    }
    D[s] = 0; //起点到自己的距离为0
    P[s] = s; //起点到自己的前驱为自己

    //创建一个集合S，用于存放已经找到最短路径的顶点
    int S[MAXVEX]; //用数组表示集合，1表示在集合中，0表示不在集合中
    for (int i = 0; i < g->vertexNum; i++)
    {
        S[i] = 0; //初始化为空集
    }

    //循环g->vertexNum次，每次找出一个最短路径
    for (int i = 0; i < g->vertexNum; i++)
    {
        //从未加入S的顶点中找出距离s最近的顶点u
        int u = -1; //记录最近的顶点编号
        int min = INT_MAX; //记录最近的距离
        for (int j = 0; j < g->vertexNum; j++)
        {
            if (S[j] == 0 && D[j] < min) //如果j不在S中且距离s更近
            {
                u = j; //更新最近的顶点编号为j
                min = D[j]; //更新最近的距离为D[j]
            }
        }

        if (u == -1) //如果没有找到最近的顶点，说明剩下的顶点都不可达，退出循环
        {
            break;
        }

        S[u] = 1; //将u加入S

        //根据u更新s到其他顶点的距离和前驱
        ENode *p = g->vexs[u].firstEdge; //指向u的第一条边
        while (p != NULL) //遍历所有与u相邻的顶点
        {
            int v = p->adjVertex; //取出边的另一端顶点编号
            int w = p->weight; //取出边的权值
            if (S[v] == 0 && D[u] + w < D[v]) //如果v不在S中且通过u可以缩短s到v的距离
            {
                D[v] = D[u] + w; //更新s到v的最短距离为s到u加上u到v的距离
                P[v] = u; //更新s到v的最短路径上的前驱为u
            }
            p = p->nextEdge; //指向下一条边
        }
    }
}
