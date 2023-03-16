
void preOrderExt(BTree bt) {
  if (bt == NULL)
    putchar('.');
  else {
    putchar(bt->data);
    preOrderExt(bt->lchild);
    preOrderExt(bt->rchild);
  }
}
