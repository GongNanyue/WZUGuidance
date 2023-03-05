
int getLeafNum(BTree rt) {
  if (rt == NULL)return 0;
  if (rt->lchild == NULL && rt->rchild == NULL)return 1;
  return getLeafNum(rt->lchild) + getLeafNum(rt->rchild);
}
