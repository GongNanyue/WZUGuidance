#include <bits/stdc++.h>

using namespace std;


#define MAXVEX 100 /*最大顶点数*/
typedef char VertexType;

struct AOENetworkStruct;
typedef struct AOENetworkStruct *AOENetwork;

typedef struct ENode {
    int adjVertex;  //边的终点编号 箭头端
    int weight;     //边权
    int earliest;   //活动最早开始时间
    int latest;     //活动最晚开始时间
    struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode {
    VertexType data;    //顶点信息/
    int inDegree;       //入度/
    int earliest;       //事件最早发生时间/
    int latest;         //事件最晚发生时间
    ENode *firstEdge; //第一条出边
} VNode;

struct AOENetworkStruct {
    VNode vexs[MAXVEX];    //点表
    int vertexNum, edgeNum; //顶点数和弧数
};

AOENetwork createGraph() {//  该函数创建一个空的AEO网并返回其指针。

    AOENetworkStruct *aoe = new AOENetworkStruct;
    return aoe;
}

int locateVertex(AOENetwork g, VertexType v) { //该函数在AEO网g中查找顶点v并返回其编号，如果不存在返回-1。
    for (int i = 0; i < g->vertexNum; ++i)
        if (v == g->vexs[i].data)
            return i;
    return -1;

}

void addVertex(AOENetwork g, VertexType v) {//该函数在AEO网g中增加顶点v(在点表最后增加，在点表中编号从0开始)，如果顶点已经存在则什么都不做。
    int idx = locateVertex(g, v);
    if (idx != -1)return;

    g->vexs[g->vertexNum].data = v;
    g->vexs[g->vertexNum].inDegree = 0;
    g->vexs[g->vertexNum].earliest = -1;
    g->vexs[g->vertexNum].latest = -1;
    g->vexs[g->vertexNum].firstEdge = NULL;
    g->vertexNum++;
}

ENode *findEdge(AOENetwork g, int i, int j) {
    ENode *p = g->vexs[i].firstEdge;
    while (p != NULL && p->adjVertex != j)
        p = p->nextEdge;
    return p;

}

void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w) {
    //该函数在AOE网g中增加一条从v1到v2权为w的边，如果已经有边则保留权最小的边。如果点v1或者v2不存在，则什么都不做。
    int i = locateVertex(g, v1), j = locateVertex(g, v2);
    if (i == -1 || j == -1)return;
    ENode *eNode = findEdge(g, i, j);
    if (eNode == NULL) {// 没有边
        ENode *eNode1 = new ENode;
        eNode1->weight = w;
        //eNode1->latest = eNode1->earliest = -1;
        eNode1->adjVertex = j;

        eNode1->nextEdge = g->vexs[i].firstEdge;
        g->vexs[i].firstEdge = eNode1;

        g->edgeNum++;
        ++g->vexs[j].inDegree;
    } else {
        eNode->weight = min(eNode->weight, w);
    }
}


stack<int> out;


int TopSort(AOENetwork g) {
    int count = 0;

    stack<int> in;
    for (int i = 0; i < g->vertexNum; ++i) {
        g->vexs[i].earliest = 0;
        if (g->vexs[i].inDegree == 0)
            in.push(i);
    }

    while (!in.empty()) {
        int u = in.top();
        in.pop();
        ++count;
        out.push(u);
        for (ENode *p = g->vexs[u].firstEdge; p != NULL; p = p->nextEdge) {
            int v = p->adjVertex;
            --(g->vexs[v].inDegree);
            if (g->vexs[v].inDegree == 0)
                in.push(v);

            g->vexs[v].earliest = max(g->vexs[v].earliest, g->vexs[u].earliest + p->weight);

        }

    }
    return count == g->vertexNum;

}

void event(AOENetwork g) {
    TopSort(g);
    for (int i = 0; i < g->vertexNum; ++i)
        g->vexs[i].latest = g->vexs[g->vertexNum - 1].earliest;

    while (!out.empty()) {
        int u = out.top();
        out.pop();

        for (ENode *p = g->vexs[u].firstEdge; p != NULL; p = p->nextEdge) {
            int v = p->adjVertex, w = p->weight;
            g->vexs[u].latest = min(g->vexs[u].latest, g->vexs[v].latest - w);
        }
    }
}

int active(AOENetwork g) {
    int cnt = 0;
    for (int u = 0; u < g->vertexNum; ++u) {
        for (ENode *p = g->vexs[u].firstEdge; p != NULL; p = p->nextEdge) {
            int v = p->adjVertex, w = p->weight;
            p->earliest = g->vexs[u].earliest;
            p->latest = g->vexs[v].latest - w;
            if (p->earliest == p->latest)
                ++cnt;
        }
    }
    return cnt;
}

int dfs(AOENetwork g, int u) {
    if (u == g->vertexNum - 1)return 1;
    int cnt = 0;
    for (ENode *p = g->vexs[u].firstEdge; p != NULL; p = p->nextEdge) {
        int v = p->adjVertex;
        if (p->earliest == p->latest)
            cnt += dfs(g, v);
    }
    return cnt;
}

int pathNum(AOENetwork g) {
    return dfs(g, 0);
}

int main() {
    int n;
    cin >> n;
    AOENetwork g = createGraph();
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        addVertex(g, s[i]);
    }

    while (true) {
        cin >> s;
        if (s == "00")break;
        int w;
        cin >> w;
        addEdge(g, s[0], s[1], w);
    }

    event(g);
    active(g);
    cout << pathNum(g) << endl;


    return 0;
}
