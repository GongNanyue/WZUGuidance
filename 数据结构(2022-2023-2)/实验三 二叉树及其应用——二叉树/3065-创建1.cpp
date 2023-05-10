BTree createTree(char s[]) {
    stack<BTree> st;
    BTree node;
    int k = 0;//1 for left tree, 2 for right tree

    for (int i = 0; s[i]; ++i) {
        if (isalpha(s[i])) {
            node = (BTree) malloc(sizeof(BTNode));
            node->lchild = node->rchild = NULL;
            sscanf(s + i, "%c", &node->data);
            if (k == 1) {
                st.top()->lchild = node;
            } else if (k == 2) {
                st.top()->rchild = node;
            }
        } else if (s[i] == '(') {
            st.push(node);
            k = 1;
        } else if (s[i] == ',') {
            k = 2;
        } else if (i != strlen(s) - 1 && s[i] == ')') {
            st.pop();
        }
    }
    if (k == 0)return node;
    else return st.top();
}
