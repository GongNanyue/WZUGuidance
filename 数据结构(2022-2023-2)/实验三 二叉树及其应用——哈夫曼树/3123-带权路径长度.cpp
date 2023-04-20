

int myGetWPL(HuffmanTree HT) {
    if (HT->lchild == NULL && HT->rchild == NULL)
        return HT->depth * HT->weight;
    
    int res = 0;
    
    if (HT->lchild != NULL)
        res += myGetWPL(HT->lchild);

    if (HT->rchild != NULL)
        res += myGetWPL(HT->rchild);
    return res;

}


int getWPL(HuffmanTree HT) {
    initDepth(HT, 0);
    return myGetWPL(HT);
}
