int locateVertex(AOENetwork g, VertexType v){ //该函数在AEO网g中查找顶点v并返回其编号，如果不存在返回-1。
    for(int i = 0;i < g->vertexNum;++i)
        if(v == g->vexs[i].data)
            return i;
    return -1;
    
}
