CSTree createTree() {
    string s;
    cin >> s;
    if (s == "#")return NULL;

    queue<CSNode *> q;
    CSNode *root, *p;
    root = (CSNode *) malloc(sizeof(CSNode));
    root->data = s[0];
    root->child = root->sibling = NULL;
    q.push(root);
    while (!q.empty()) {
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0) {
                p = q.front();
                q.pop();
                if (s[i] != '#') {
                    p->child = (CSNode *) malloc(sizeof(CSNode));
                    p = p->child;
                    p->data = s[i];
                    p->child = p->sibling = NULL;
                    q.push(p);
                }
            } else {
                if (s[i] != '#') {
                    p->sibling = (CSNode *) malloc(sizeof(CSNode));
                    p = p->sibling;
                    p->data = s[i];
                    p->child = p->sibling = NULL;
                    q.push(p);
                }
            }
        }
    }
    return root;
}
