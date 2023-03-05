int locateVertex(Graph g, VertexType v) {
  for(int i = 0;i < g->vertexNum;++i)
    if(g->vexs[i] == v)return i;
  return -1;
}
