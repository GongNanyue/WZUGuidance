
ElementType getData(char s[], int idx) {
    ElementType res;
    sscanf(s + idx, "%c", &res);
    return res;
}


CSTree createTree(char s[]) {
    CSTree root = NULL, node = NULL;
    stack<CSTree> st;
    int k = 0;

    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '(') {
            st.push(node);
            k = 1;
        } else if (s[i] == ',') {
            k = 2;
        } else if (s[i] == ')') {
            st.pop();
        } else {
            node = (CSNode *) malloc(sizeof(CSNode));
            node->data = getData(s,i);
            node->child = node->sibling = NULL;
            if (root == NULL) {
                root = node;
            } else {
                if (k == 1) {
                    st.top()->child = node;
                } else if (k == 2) {
                    CSNode *chd = st.top()->child;
                    while (chd->sibling != NULL) {
                        chd = chd->sibling;
                    }
                    chd->sibling = node;
                }
            }
        }
    }
    return root;
}
