BSTNode* findMin(BSTree bst){
  if(bst==NULL)return NULL;
  if(bst->lchild!=NULL)return findMin(bst->lchild);
  return bst;
}
