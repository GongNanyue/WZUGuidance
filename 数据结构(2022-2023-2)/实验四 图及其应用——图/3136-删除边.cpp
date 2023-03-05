void delEdge(Graph g, VertexType x, VertexType y) {
  int xIdx = locateVertex(g, x), yIdx = locateVertex(g, y);
  if (xIdx == -1 || yIdx == -1 || !g->edge[xIdx][yIdx])return;
  g->edge[xIdx][yIdx] = g->edge[yIdx][xIdx] = 0;
  --g->edgeNum;
}
