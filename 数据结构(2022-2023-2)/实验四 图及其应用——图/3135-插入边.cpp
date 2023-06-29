void addEdge(Graph g, VertexType x, VertexType y) {
  int xIdx = locateVertex(g, x), yIdx = locateVertex(g, y);
  if (xIdx == -1 || yIdx == -1 || g->edge[xIdx][yIdx])return;
  g->edge[xIdx][yIdx] = g->edge[yIdx][xIdx] = 1; // 图用1代表有边 0代表没有边
  ++g->edgeNum; // 加上边数
}
