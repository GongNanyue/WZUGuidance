
Graph createGraph(){
  Graph graph = (Graph) malloc(sizeof(MGraph));
  graph->vertexNum = graph->edgeNum = 0;

  return graph;
}
