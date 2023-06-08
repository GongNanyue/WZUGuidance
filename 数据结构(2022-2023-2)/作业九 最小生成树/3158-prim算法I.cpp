//Prim算法求g的最小生成树的权(从顶点u开始，已知u在图g中)，并返回最小生成树的权。 
//如果最小生成树不存在，则返回-1。
int Prim(Graph g, VertexType u){
  //定义一个数组，用来存储每个顶点到最小生成树的最短距离
  int lowcost[MAXVEX];
  //定义一个数组，用来存储每个顶点的前驱顶点
  int prenode[MAXVEX];
  //定义一个变量，用来存储最小生成树的权
  int mincost = 0;
  //找到顶点u在图g中的位置
  int k = locateVertex(g,u);
  //如果顶点u不存在，返回-1
  if(k == -1) return -1;
  //初始化lowcost和prenode数组
  for(int i = 0; i < g->vertexNum; i++){
    //如果i和k有边相连，lowcost[i]为边的权值，否则为无穷大
    lowcost[i] = INT_MAX;
    ENode *p = g->vexs[k].firstEdge;
    while(p){
      if(p->adjVertex == i){
        lowcost[i] = p->weight;
        break;
      }
      p = p->nextEdge;
    }
    //prenode[i]为k
    prenode[i] = k;
  }
  //将k加入到最小生成树中，lowcost[k]设为0
  lowcost[k] = 0;
  //循环g->vertexNum-1次，每次找到一个距离最小生成树最近的顶点，并加入到最小生成树中
  for(int i = 1; i < g->vertexNum; i++){
    //定义一个变量，用来存储当前最小距离
    int min = INT_MAX;
    //定义一个变量，用来存储当前最近的顶点
    int j = -1;
    //遍历lowcost数组，找到最小的值和对应的顶点
    for(int m = 0; m < g->vertexNum; m++){
      if(lowcost[m] != 0 && lowcost[m] < min){
        min = lowcost[m];
        j = m;
      }
    }
    //如果没有找到合适的顶点，说明图不连通，返回-1
    if(j == -1) return -1;
    //将j加入到最小生成树中，更新mincost和lowcost数组
    mincost += min;
    lowcost[j] = 0;
    ENode *p = g->vexs[j].firstEdge;
    while(p){
      if(lowcost[p->adjVertex] != 0 && p->weight < lowcost[p->adjVertex]){
        lowcost[p->adjVertex] = p->weight;
        prenode[p->adjVertex] = j;
      }
      p = p->nextEdge;
    }
  }
  //返回最小生成树的权
  return mincost;
}
