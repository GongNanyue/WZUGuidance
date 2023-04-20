#include <bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
    int visited[MAXVEX];//遍历标记. 1:已遍历  0:未遍历
    int vertexNum, edgeNum;
} MGraph, *Graph;


Graph createGraph() {
    Graph graph = (Graph) malloc(sizeof(MGraph));
    graph->vertexNum = graph->edgeNum = 0;
    return graph;
}

int locateVertex(Graph g, VertexType v) {
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->vexs[i] == v)return i;
    return -1;
}

void addVertex(Graph g, VertexType v) {
    if (locateVertex(g, v) != -1)return;
    g->vexs[g->vertexNum] = v;
    ++g->vertexNum;
}

void addEdge(Graph g, VertexType x, VertexType y) {
    int xIdx = locateVertex(g, x), yIdx = locateVertex(g, y);
    if (xIdx == -1 || yIdx == -1 || g->edge[xIdx][yIdx])return;
    g->edge[xIdx][yIdx] = g->edge[yIdx][xIdx] = 1;
    ++g->edgeNum;
}

void delEdge(Graph g, VertexType x, VertexType y) {
    int xIdx = locateVertex(g, x), yIdx = locateVertex(g, y);
    if (xIdx == -1 || yIdx == -1 || !g->edge[xIdx][yIdx])return;
    g->edge[xIdx][yIdx] = g->edge[yIdx][xIdx] = 0;
    --g->edgeNum;
}

void delVertex(Graph g, VertexType v) {
    int u = locateVertex(g, v);
    if (u == -1)return;

    for (int i = 0; i < g->vertexNum; ++i)
        delEdge(g, v, g->vexs[i]);

    for (int i = u; i < g->vertexNum - 1; ++i)
        g->vexs[i] = g->vexs[i + 1];

    for (int i = u; i < g->vertexNum - 1; ++i)
        for (int j = 0; j < u; ++j)
            g->edge[i][j] = g->edge[i + 1][j];

    for (int j = u; j < g->vertexNum - 1; ++j)
        for (int i = 0; i < u; ++i)
            g->edge[i][j] = g->edge[i][j + 1];

    for (int i = u; i < g->vertexNum - 1; ++i)
        for (int j = u; j < g->vertexNum - 1; ++j)
            g->edge[i][j] = g->edge[i + 1][j + 1];

    g->vertexNum--;


}

int degree(Graph g, VertexType v) {
    int u = locateVertex(g, v);
    int out = 0;
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->edge[u][i] == 1)
            ++out;
    return out;
}

void DFS(Graph g, int i) {
    g->visited[i] = 1;
    for (int v = 0; v < g->vertexNum; ++v)
        if (g->edge[i][v] == 1 && g->visited[v] == 0)
            DFS(g, v);
}

void BFS(Graph g, int i) {
    queue<int> q;
    q.push(i);
    g->visited[i] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < g->vertexNum; ++v)
            if (g->edge[u][v] == 1 && g->visited[v] != 0) {
                q.push(v);
                g->visited[v] = 1;
            }
    }

}

int connect(Graph g, VertexType v, VertexType u) {
    memset(g->visited, 0, sizeof g->visited);
    int i = locateVertex(g, v), j = locateVertex(g, u);
    BFS(g, i);
    return g->visited[j];

}

int p[MAXVEX];

int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}

bool isConnect(int u, int v) {
    return find(u) == find(v);
}

void merge(int u, int v) {

    p[find(v)] = find(u);
}

int connectedComps(Graph g) {
    for (int i = 0; i < g->vertexNum; ++i)
        p[i] = i;
    for (int i = 0; i < g->vertexNum; ++i)
        for (int j = i + 1; j < g->vertexNum; ++j)
            if (g->edge[i][j] == 1)
                merge(i, j);
    int cnt = 0;
    for (int i = 0; i < g->vertexNum; ++i)
        if (p[i] == i)
            ++cnt;
    return cnt;
}

int distance(Graph g, VertexType v, VertexType u) {
    int a = locateVertex(g, v), b = locateVertex(g, u);

    memset(g->visited, false, sizeof g->visited);
    int dist[g->vertexNum];
    memset(dist, 0x3f, sizeof dist);
    dist[a] = 0;

    for (int i = 0; i < g->vertexNum; ++i) {
        int x = -1, minDis = 0x3f3f3f3f;
        for (int j = 0; j < g->vertexNum; ++j)
            if (g->visited[j] == 0 && dist[j] < minDis) {
                x = j;
                minDis = dist[j];
            }

        g->visited[x] = true;
        for (int j = 0; j < g->vertexNum; ++j)
            if (g->edge[x][j] == 1)
                if (dist[j] > dist[x] + g->edge[x][j])
                    dist[j] = dist[x] + g->edge[x][j];
    }
    if (dist[b] == 0x3f3f3f3f)
        return 0;
    else return dist[b];

}

void destroyGraph(Graph g){
    //free(g);
    //直接这样做也可以AC

}


int main() {


    return 0;
}
