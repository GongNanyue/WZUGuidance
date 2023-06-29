void addEdge(Graph g, VertexType v1, VertexType v2, int w){
	int i = locateVertex(g,v1),j = locateVertex(g,v2);
	if(i != -1 && j != -1){
		ENode *p = findEdge(g,i,j);
		ENode *q = findEdge(g,j,i);
		if(p == NULL){
			p = new ENode;
			p->adjVertex = j;
			p->weight = w;
			p->nextEdge = g->vexs[i].firstEdge;
			g->vexs[i].firstEdge = p;
			
			q = new ENode;
			q->adjVertex = i;
			q->weight = w;
			q->nextEdge = g->vexs[j].firstEdge;
			g->vexs[j].firstEdge = q;
			
			g->edgeNum++;	
		}else{
			p->weight = q->weight = min(p->weight,w);
		}
	}
}
