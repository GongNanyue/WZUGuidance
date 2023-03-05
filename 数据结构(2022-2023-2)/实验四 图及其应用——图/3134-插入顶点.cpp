void addVertex(Graph g, VertexType v) {
  if (locateVertex(g, v) != -1)return;
  g->vexs[g->vertexNum] = v;
  ++g->vertexNum;
}
