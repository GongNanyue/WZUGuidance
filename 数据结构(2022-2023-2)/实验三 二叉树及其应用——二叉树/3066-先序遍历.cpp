void preOrder(BTree bt) {
    if (!bt)return;
    printf("%c", bt->data);
    preOrder(bt->lchild);
    preOrder(bt->rchild);
}
