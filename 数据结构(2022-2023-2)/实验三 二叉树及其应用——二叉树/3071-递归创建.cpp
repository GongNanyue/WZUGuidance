
BTree createTree(char s[], int left, int right) {
    if (left > right) return NULL;

    int leftBracket = -1, comma = -1, rightBracket = -1, bracketCnt = 0;
    for (int i = left; i <= right; ++i) {
        if (s[i] == '(') {
            bracketCnt++;
            if (bracketCnt == 1)
                leftBracket = i;
        } else if (s[i] == ',') {
            if (bracketCnt == 1)
                comma = i;
        } else if (s[i] == ')') {
            bracketCnt--;
            if (bracketCnt == 0)
                rightBracket = i;
        }
    }

    BTNode *parentNode = (BTNode *) malloc(sizeof(BTNode));
    parentNode->data = -1;
    parentNode->lchild = parentNode->rchild = NULL;
    sscanf(s + left, "%c", &parentNode->data);

    if (leftBracket == -1 && comma == -1 && rightBracket == -1) {

        return parentNode;
    } else if (leftBracket + 1 == comma) {
        parentNode->rchild = createTree(s, comma + 1, rightBracket - 1);
    } else if (rightBracket - 1 == comma) {
        parentNode->lchild = createTree(s, leftBracket + 1, comma - 1);
    } else {
        parentNode->rchild = createTree(s, comma + 1, rightBracket - 1);
        parentNode->lchild = createTree(s, leftBracket + 1, comma - 1);
    }

    return parentNode;
}
