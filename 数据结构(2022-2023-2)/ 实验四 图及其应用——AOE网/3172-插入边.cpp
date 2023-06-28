void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w){
	int i = locateVertex(g,v1);
	int j = locateVertex(g,v2);
	
	if(i != -1 && j != -1){
		ENode *p = findEdge(g,i,j);
		if(p != NULL){
			p->weight = min(p->weight,w);	
		}else{
			p = new ENode;
			p->weight = w;
			p->adjVertex = j;
			
			p->nextEdge = g->vexs[i].firstEdge;
			g->vexs[i].firstEdge = p;
			g->edgeNum++;
			g->vexs[j].inDegree++;
		}
	}
}
