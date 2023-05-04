

void postOrder(CSTree root) {
    if (root != NULL) {
        postOrder(root->child);
        cout << root->data;
        postOrder(root->sibling);

    }
}
