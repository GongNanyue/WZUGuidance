void postOrder(BTree rt) {
    if (!rt)return;
    postOrder(rt->lchild);
    postOrder(rt->rchild);
    printf("%c", rt->data);
}
