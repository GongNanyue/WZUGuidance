// Prim(Graph g, VertexType u, Graph t) function
int Prim(Graph g, VertexType u, Graph t) {
  // initialize the minimum spanning tree weight to 0
  int weight = 0;
  // create an array to store the visited vertices
  int visited[MAXVEX] = {0};
  // locate the starting vertex u in g
  int u_index = locateVertex(g, u);
  // check if u is valid
  if (u_index == -1) {
    return -1; // u is not in g
  }
  // add u to the visited array
  visited[u_index] = 1;
  // add u to the minimum spanning tree t
  addVertex(t, u);
  // create a variable to store the number of edges added to t
  int edge_count = 0;
  // loop until all vertices are visited or t has n-1 edges
  while (edge_count < g->vertexNum - 1) {
    // create variables to store the minimum weight edge and its endpoints
    int min_weight = INT_MAX;
    int min_u = -1;
    int min_v = -1;
    // loop through all the vertices in g
    for (int i = 0; i < g->vertexNum; i++) {
      // if i is visited, loop through its adjacent vertices
      if (visited[i]) {
        ENode *p = g->vexs[i].firstEdge;
        while (p) {
          // if p->adjVertex is not visited and p->weight is less than min_weight
          if (!visited[p->adjVertex] && p->weight < min_weight) {
            // update min_weight, min_u and min_v
            min_weight = p->weight;
            min_u = i;
            min_v = p->adjVertex;
          }
          // move to the next edge
          p = p->nextEdge;
        }
      }
    }
    // check if a valid edge is found
    if (min_u == -1 || min_v == -1) {
      return -1; // no minimum spanning tree exists
    }
    // add the minimum weight edge and its endpoint to t
    addVertex(t, g->vexs[min_v].data);
    addEdge(t, g->vexs[min_u].data, g->vexs[min_v].data, min_weight);
    // mark min_v as visited
    visited[min_v] = 1;
    // update the weight and edge_count
    weight += min_weight;
    edge_count++;
  }
  // return the minimum spanning tree weight
  return weight;
}
