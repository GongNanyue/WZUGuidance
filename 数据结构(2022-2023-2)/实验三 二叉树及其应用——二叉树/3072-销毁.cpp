
void destroyTree(BTree bt) {
  if (!bt)return;
  destroyTree(bt->lchild);
  destroyTree(bt->rchild);
  free(bt);
}
