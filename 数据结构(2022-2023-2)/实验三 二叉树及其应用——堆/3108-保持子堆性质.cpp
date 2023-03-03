void heapify(Heap H,int i){
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
