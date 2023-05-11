int insert(Heap H, ElementType x){
	//在capacity已经满的情况下插入失败
	if(full(H)) return  0;
	++(H->size);
	H->data[H->size] = x;
	increase(H,H->size,x);
	return 1;
}
