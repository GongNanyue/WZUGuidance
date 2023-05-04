
void preOrder(CSTree root) {
    if (root != NULL) {
        cout << root->data;
        preOrder(root->child);
        preOrder(root->sibling);
    }

}
