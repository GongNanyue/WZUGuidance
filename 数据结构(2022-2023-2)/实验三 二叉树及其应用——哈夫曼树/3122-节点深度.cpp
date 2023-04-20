void initDepth(HuffmanTree HT,int depth) {
    if (HT == nullptr) {
        return;
    }
    HT->depth = depth;
    initDepth(HT->lchild, depth + 1);
    initDepth(HT->rchild, depth + 1);
}
