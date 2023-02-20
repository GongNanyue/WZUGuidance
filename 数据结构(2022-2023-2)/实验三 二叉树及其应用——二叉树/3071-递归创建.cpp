
BTree createTree(char s[], int left, int right) {
    if (left > right) {
        return NULL;
    }
    BTNode * node = (BTNode*)malloc(sizeof(BTNode));
    node->data = s[left];
    node->lchild = NULL;
    node->rchild = NULL;
    if(left == right) return node;
    int i = left + 1;
    int count = 0;
    while (i <= right) {
        if (s[i] == '(') {
            count++;
        } else if (s[i] == ')') {
            count--;
        } else if (count == 1 && (s[i] == ',' || i == right)) {
            break;
        }
        i++;
    }
    node->lchild = createTree(s, left + 2, i - 1);
    node->rchild = createTree(s, i + 1, right - 1);
    return node;
}
