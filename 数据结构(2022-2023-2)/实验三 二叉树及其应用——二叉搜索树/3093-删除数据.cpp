BSTree deleteNode(BSTree bst, ElementType x) {
  if (bst == NULL) return bst; // 树为空，直接返回

  if (x < bst->data) {
    bst->lchild = deleteNode(bst->lchild, x); // 递归删除左子树中的节点
  } else if (x > bst->data) {
    bst->rchild = deleteNode(bst->rchild, x); // 递归删除右子树中的节点
  } else { // 找到待删除结点
    if (bst->lchild == NULL) { // 没有左子树
      BSTree tmp = bst->rchild;
      free(bst);
      return tmp;
    } else if (bst->rchild == NULL) { // 没有右子树
      BSTree tmp = bst->lchild;
      free(bst);
      return tmp;
    } else { // 既有左子树又有右子树
      BSTNode *minNode = findMin(bst->rchild); // 找到右子树中最小值节点
      bst->data = minNode->data; // 用最小值节点的值覆盖待删除结点的值
      bst->rchild = deleteNode(bst->rchild, minNode->data); // 删除右子树中最小值节点
    }
  }
  return bst;
}
