void increase(Heap H, int i, ElementType x){
	if(x < H->data[i])return;
	H->data[i] = x;
	while(H->data[parent(i)] < H->data[i] && i != 1){
		swap(H,i,parent(i));
		i = parent(i);
	}
}
