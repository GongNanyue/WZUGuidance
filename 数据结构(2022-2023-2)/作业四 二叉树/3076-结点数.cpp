int getNum(BTree rt){
  if(rt == NULL)return 0;
  return getNum(rt->lchild) + getNum(rt->rchild) + 1;
}
