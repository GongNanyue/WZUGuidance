//Prim算法求最小生成树的权
int Prim(Graph g, VertexType u) {
  //如果图为空或顶点数小于2，返回-1
  if (g == NULL || g->vertexNum < 2) {
    return -1;
  }
  //找到顶点u在图中的位置，如果不存在，返回-1
  int uIndex = locateVertex(g, u);
  if (uIndex == -1) {
    return -1;
  }
  //定义一个数组lowcost，存储当前生成树到其他顶点的最小权值
  int lowcost[MAXVEX];
  //定义一个数组adjvex，存储当前生成树到其他顶点的最近邻顶点
  int adjvex[MAXVEX];
  //初始化lowcost和adjvex
  for (int i = 0; i < g->vertexNum; i++) {
    //如果i和u有边相连，lowcost[i]为边的权值，否则为无穷大
    lowcost[i] = g->edge[uIndex][i] ? g->edge[uIndex][i] : INT_MAX;
    //adjvex[i]为u
    adjvex[i] = uIndex;
  }
  //将u加入生成树，lowcost[uIndex]设为0
  lowcost[uIndex] = 0;
  //定义一个变量minWeight，存储最小生成树的权值
  int minWeight = 0;
  //循环n-1次，每次找到一个最小权值的边加入生成树
  for (int i = 1; i < g->vertexNum; i++) {
    //定义一个变量minCost，存储当前最小权值
    int minCost = INT_MAX;
    //定义一个变量minIndex，存储当前最小权值对应的顶点位置
    int minIndex = -1;
    //遍历lowcost数组，找到最小权值和对应的顶点位置
    for (int j = 0; j < g->vertexNum; j++) {
      if (lowcost[j] != 0 && lowcost[j] < minCost) {
        minCost = lowcost[j];
        minIndex = j;
      }
    }
    //如果没有找到最小权值，说明图不连通，返回-1
    if (minIndex == -1) {
      return -1;
    }
    //将最小权值加入minWeight
    minWeight += minCost;
    //将最小权值对应的顶点加入生成树，lowcost[minIndex]设为0
    lowcost[minIndex] = 0;
    //更新lowcost和adjvex数组，考虑新加入的顶点
    for (int k = 0; k < g->vertexNum; k++) {
      //如果k和minIndex有边相连，并且边的权值小于lowcost[k]
      if (g->edge[minIndex][k] && g->edge[minIndex][k] < lowcost[k]) {
        //更新lowcost[k]为边的权值
        lowcost[k] = g->edge[minIndex][k];
        //更新adjvex[k]为minIndex
        adjvex[k] = minIndex;
      }
    }
  }
  //返回最小生成树的权值
  return minWeight;
}
