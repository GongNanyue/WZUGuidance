
// Dijkstra函数的定义
void Dijkstra(Graph g, int s, int D[], int P[]) {
    // 定义一个数组visited，记录顶点是否被访问过
    int visited[MAXVEX];
    // 初始化visited，D和P数组
    for (int i = 0; i < g->vertexNum; i++) {
        visited[i] = 0; // 初始时都未被访问过
        D[i] = g->edge[s][i]; // 初始时D[i]为s到i的边的权值，如果没有边则为INT_MAX
        if (D[i] < INT_MAX) // 如果s到i有边，则P[i]为s，否则为-1
            P[i] = s;
        else
            P[i] = -1;
    }
    // 将s标记为已访问，并将D[s]和P[s]设为0
    visited[s] = 1;
    D[s] = 0;
    P[s] = 0;
    // 循环g->vertexNum-1次，每次找出一个未访问的距离s最近的顶点u，并更新D和P数组
    for (int i = 1; i < g->vertexNum; i++) {
        // 定义一个变量min，记录当前最小的距离，初始为INT_MAX
        int min = INT_MAX;
        // 定义一个变量u，记录当前最近的顶点，初始为-1
        int u = -1;
        // 遍历所有顶点，找出未访问且距离s最近的顶点u
        for (int j = 0; j < g->vertexNum; j++) {
            if (visited[j] == 0 && D[j] < min) {
                min = D[j];
                u = j;
            }
        }
        // 如果没有找到u，则说明剩下的顶点都不可达，跳出循环
        if (u == -1)
            break;
        // 否则，将u标记为已访问
        visited[u] = 1;
        // 遍历所有顶点，更新D和P数组
        for (int k = 0; k < g->vertexNum; k++) {
            // 如果k未被访问且u到k有边且s到k的距离大于s到u加上u到k的距离，则更新D[k]和P[k]
            if (visited[k] == 0 && g->edge[u][k] < INT_MAX && D[k] > D[u] + g->edge[u][k]) {
                D[k] = D[u] + g->edge[u][k];
                P[k] = u;
            }
        }
    }
}
