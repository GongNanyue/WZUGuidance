void heapify(Heap H,int i){
	//本质上就是down操作 
	//这个函数也可以叫做down()
	int largestIdx = i;
	if(left(i) <= H->size && H->data[largestIdx] < H->data[left(i)]) 
		largestIdx = left(i);
	if(right(i) <= H->size && H->data[largestIdx] < H->data[right(i)])
		largestIdx = right(i);
	if(largestIdx != i){
		std::swap(H->data[i],H->data[largestIdx]);
		heapify(H,largestIdx);
	}
}
