```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAXVEX 1000 //×î´ó¶¥µãÊý
typedef char VertexType;

typedef struct ENode
{
    int adjVertex;  //¸Ã±ßËùÖ¸µÄ¶¥µã±àºÅ
    int weight;     //±ßÈ¨
    struct ENode *nextEdge;  //ÏÂÒ»Ìõ±ß
} ENode;

typedef struct VNode
{
    VertexType data;   //¶¥µãÐÅÏ¢
    int visited; //±éÀú±ê¼Ç. 1:ÒÑ±éÀú  0:Î´±éÀú
    ENode *firstEdge; //µÚÒ»Ìõ³ö±ß
} VNode;

typedef struct
{
    VNode vexs[MAXVEX];
    int vertexNum,edgeNum;  //µãÊýºÍ±ßÊý
}AdjGraph,*Graph;


Graph createGraph(){
	return new AdjGraph;
}

int locateVertex(Graph g, VertexType v){
	for(int i = 0;i < g->vertexNum;++i){
		if(g->vexs[i].data == v){
			return  i;
		}
	}
	return -1;
}

void addVertex(Graph g, VertexType v){
	if(locateVertex(g,v) == -1){
		g->vexs[g->vertexNum++].data = v;
	}
}

ENode* findEdge(Graph g, int i, int j){
	ENode *p = g->vexs[i].firstEdge;
	for(;p != NULL;p = p->nextEdge){
		if(p->adjVertex == j){
			return p;
		}
	} 
	return p;
}

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

int degree(Graph g, VertexType v){
	int cnt = 0;
	int u = locateVertex(g,v);
	for(ENode *p = g->vexs[u].firstEdge;p != NULL;p = p->nextEdge){
		cnt++;
	} 
	return cnt;
}

ENode *findPreENode(Graph g,int i,int j){
	//¼Ù¶¨ÓÐi-jÕâÌõ±ß 
	ENode *pre = g->vexs[i].firstEdge;
	if(pre->adjVertex == j)return NULL;//Èç¹ûµÚÒ»Ìõ±ß¾ÍÊÇi--j 
	else{
		while(pre->nextEdge != NULL && pre->nextEdge->adjVertex != j)
			pre = pre->nextEdge;
		return pre;
	}
}
void delEdge(Graph g,VertexType x,VertexType y){
	int u = locateVertex(g,x);
	int v = locateVertex(g,y);
	
	if(u != -1 && v != -1){
		ENode *p = findEdge(g,u,v);
		if(p == NULL)return;
		ENode *pre = findPreENode(g,u,v);
		
		if(pre == NULL){
			g->vexs[u].firstEdge = p->nextEdge;
		}else{
			pre->nextEdge = p->nextEdge;
		}
		delete p;
		
		
		p = findEdge(g,v,u);
		if(p == NULL)return;	
		pre = findPreENode(g,v,u);
		
		if(pre == NULL){
			g->vexs[v].firstEdge = p->nextEdge;
		}else{
			pre->nextEdge = p->nextEdge;
		}
		delete p;
		
		g->edgeNum--;
	}
}

void delVertex(Graph g, VertexType v){
	int idx = locateVertex(g,v);
	if(idx != -1){
		
		for(ENode *p = g->vexs[i].firstEdge;p != NULL;p = p->nextEdge){
			delEdge(g,v,g->vexs[p->adjVertex].data);
		}
		
		// °Ñ×îºóÒ»¸ö½Úµã¸´ÖÆµ½idxËùÔÚµÄÎ»ÖÃ  
		if(idx != g->vertexNum - 1){
			g->vexs[idx] = g->vexs[g->vertexNum-1]; // °Ñ´Ó×îºóÒ»¸ö½Úµã¿ªÍ·µÄËùÓÐµÄENode¶¼¸´ÖÆÁË¹ýÀ´
			// ÏÂÃæÒª°Ñ u -- g->vertexNum - 1 µÄ±ß¶¼ÐÞ¸Ä³É u -- idx 
			for(int j = 0;j < g->vertexNum - 1;++j){
				for(ENode *p = g->vexs[j].firstEdge;p != NULL;p = p->nextEdge){
					if(p->adjVertex == g->vertexNum -1){
						p->adjVertex = idx;
					}
				}
			}
		}
		g->vertexNum--;	
	}
}

void DFS(Graph g, int i){
	stack<int> st;
	st.push(i);
	while(!st.empty()){
		int u = st.top();
		st.pop();
		g->vexs[u].visited = 1;
		for(ENode *p = g->vexs[u].firstEdge;p != NULL;p = p->nextEdge){
			if(g->vexs[p->adjVertex].visited == 0){
				st.push(p->adjVertex);
			}
		}
	}
}

void BFS(Graph g, int i){
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		g->vexs[u].visited = 1;
		for(ENode *p = g->vexs[u].firstEdge;p != NULL;p = p->nextEdge){
			int v = p->adjVertex;
			if(g->vexs[v].visited == 0){
				q.push(v);
			}
		}
	}
}

int leader[MAXVEX];

int findleader(int u){
	return leader[u] == u ? u : leader[u] = findleader(leader[u]);
}

void merge(int u,int v){
	leader[findleader(u)] = findleader(v);
}

bool query(int u,int v){
	return findleader(u) == findleader(v);
}
int connect(Graph g, VertexType x, VertexType y){
	for(int i = 0;i < g->vertexNum;++i) leader[i] = i;// ²¢²é¼¯³õÊ¼»¯ 
	
	
	for(int i = 0;i < g->vertexNum;++i){
		for(ENode *p = g->vexs[i].firstEdge;p != NULL;p = p->nextEdge){
			merge(i,p->adjVertex);
		}
	}
	
	int u = locateVertex(g,x);
	int v = locateVertex(g,y);
	return query(u,v);
}

int connectedComps(Graph g){
	for(int i = 0;i < g->vertexNum;++i) leader[i] = i;// ²¢²é¼¯³õÊ¼»¯ 
	
	
	for(int i = 0;i < g->vertexNum;++i){
		for(ENode *p = g->vexs[i].firstEdge;p != NULL;p = p->nextEdge){
			merge(i,p->adjVertex);
		}
	}
	
	int cnt = 0;
	for(int i = 0;i < g->vertexNum;++i){
		if(leader[i] == i){
			cnt++;
		}
	}
	return cnt;
}

void destroyGraph(Graph g){
	delete g;
}
int main(){
	
}
```
