
BSTNode *find(BSTree bst, ElementType x) {
  BSTNode *np = bst;
  while (np != NULL) {
    if (np->data == x)break;
    if (np->data > x) np = np->lchild;
    else if (np->data < x) np = np->rchild;
  }
  return np;
}
