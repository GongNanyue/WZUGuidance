#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
} BSTNode, *BSTree;

BSTree insert(BSTree bst, ElementType x) {
    if (bst == NULL) {
        BSTNode *node = (BSTNode *) malloc(sizeof(BSTNode));
        node->data = x;
        node->lchild = node->rchild = NULL;
        return node;
    }
    if (x < bst->data) {
        bst->lchild = insert(bst->lchild, x);
    } else if (x > bst->data) {
        bst->rchild = insert(bst->rchild, x);
    } else {
        return bst;
    }
    return bst;
}

BSTree destroyBSTree(BSTree bst) {
    if (bst == NULL)return bst;
    destroyBSTree(bst->rchild);
    destroyBSTree(bst->lchild);
    free(bst);
    bst = NULL;
    return bst;
}

BSTree createFromIn() {
    int n;
    cin >> n;

    BSTNode *root = NULL;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    return root;
}

void outputGeneralizedList(BSTree bst) {
    if (!bst)return;
    printf("%d", bst->data);
    if (!bst->rchild && !bst->lchild)return;
    putchar('(');
    if (bst->lchild) {
        outputGeneralizedList(bst->lchild);
    }
    putchar(',');
    if (bst->rchild) {
        outputGeneralizedList(bst->rchild);
    }
    putchar(')');

}

int main() {
    BSTree r = createFromIn();
    outputGeneralizedList(r);
    cout << "\n";

    return 0;
}
