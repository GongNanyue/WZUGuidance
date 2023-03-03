int insert(Heap H, ElementType x){
	if(full(H)) return  0;
	++(H->size);
	H->data[H->size] = x;
	increase(H,H->size,x);
	return 1;
}
