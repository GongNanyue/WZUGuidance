BSTree insert(BSTree bst, ElementType x) {
  if (bst == NULL) {
    BSTNode *node = (BSTNode *) malloc(sizeof(BSTNode));
    node->data = x;
    node->lchild = node->rchild = NULL;
    return node;
  }
  if (x < bst->data) {
    bst->lchild = insert(bst->lchild, x);
  } else if (x > bst->data) {
    bst->rchild = insert(bst->rchild, x);
  } else {
    return bst;
  }
  return bst;
}
