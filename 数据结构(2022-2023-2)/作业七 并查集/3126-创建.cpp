
Set createSet(int size) {
    Set set = (Set ) malloc( sizeof (SNode));
    set->size = size;
    set->parent = (int*) malloc( sizeof(int ) * size);
    for(int i = 0;i < size;++i)
        set->parent[i] = -1;
    return  set;
}
