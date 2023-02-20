void printTree(BTree bt) {
  if (!bt)return;
  printf("%c", bt->data);
  if (!bt->rchild && !bt->lchild)return;
  putchar('(');
  if (bt->lchild) {
    printTree(bt->lchild);
  }
  putchar(',');
  if (bt->rchild) {
    printTree(bt->rchild);
  }
  putchar(')');
}
