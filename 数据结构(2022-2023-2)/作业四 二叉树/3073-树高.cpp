int getDepth(BTree rt) {
  if (rt == NULL)return 0;
  return max(getDepth(rt->lchild), getDepth(rt->rchild)) + 1;
}
