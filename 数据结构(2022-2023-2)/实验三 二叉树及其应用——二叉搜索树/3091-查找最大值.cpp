BSTNode* findMax(BSTree bst){
  if(bst==NULL)return NULL;
  if(bst->rchild!=NULL)return findMax(bst->rchild);
  return bst;
}
