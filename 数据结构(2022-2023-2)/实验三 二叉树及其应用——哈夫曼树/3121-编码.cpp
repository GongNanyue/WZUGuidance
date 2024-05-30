void huffmanCode(HuffmanTree HT, int code[], int depth) {
    // 检查当前节点是否为叶子节点
    if (HT->lchild == NULL && HT->rchild == NULL) {
        // 输出当前节点的值和编码
        printf("%d:", HT->value);
        for (int i = 0; i < depth; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
        return;
    }

    // 左子树编码：当前节点编码 + 0
    code[depth] = 0;
    if (HT->lchild) {
        huffmanCode(HT->lchild, code, depth + 1);
    }

    // 右子树编码：当前节点编码 + 1
    code[depth] = 1;
    if (HT->rchild) {
        huffmanCode(HT->rchild, code, depth + 1);
    }
}