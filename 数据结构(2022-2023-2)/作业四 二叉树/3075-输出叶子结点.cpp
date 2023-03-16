
void leafNode(BTree rt) {
  if(rt->lchild == NULL && rt->rchild == NULL)
    putchar(rt->data);
  if(rt->lchild != NULL)
    leafNode(rt->lchild );
  if(rt->rchild != NULL)
    leafNode(rt->rchild);
}
