BSTree destroyBSTree(BSTree bst) {
  if(bst==NULL)return bst;
  destroyBSTree(bst->rchild);
  destroyBSTree(bst->lchild);
  free(bst);
  bst = NULL;
  return bst;
}
