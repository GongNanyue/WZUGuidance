
void inOrder(BTree bt){
    if (!bt)return;
    inOrder(bt->lchild);
    printf("%c", bt->data);
    inOrder(bt->rchild);
}
