void inOrder(BSTree bst){
  if(bst->lchild!=NULL)inOrder(bst->lchild);
  printf("%d ",bst->data);
  if(bst->rchild!=NULL)inOrder(bst->rchild);
}
