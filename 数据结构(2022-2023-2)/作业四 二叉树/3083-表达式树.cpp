#include <bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef struct Node {
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
} BTNode, *BTree;

void MidOrder(BTNode *node) {
    if (node == NULL)return;
    MidOrder(node->lchild);
    cout << node->data;
    MidOrder(node->rchild);
}


void LastOrder(BTNode *node) {
    if (node == NULL)return;
    LastOrder(node->lchild);
    LastOrder(node->rchild);
    cout << node->data;
}


void expressionPreOrder(BTree tree) {
    if (tree == NULL)return;
    cout << tree->data;
    expressionPreOrder(tree->lchild);
    expressionPreOrder(tree->rchild);
}

void expressionInOrder(BTree tree) {
    if (tree == NULL)return;
    expressionInOrder(tree->lchild);
    cout << tree->data;
    expressionInOrder(tree->rchild);
}

BTree createExpressionTree(string postString) {
    if (postString.empty())
        return NULL;
    stack<BTNode *> stack;
    for (int i = 0; i < postString.size(); ++i) {
        char c = postString[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            BTNode *a, *b;
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            BTNode *node = (BTNode *) malloc(sizeof(BTNode));
            node->data = c;
            node->lchild = b;
            node->rchild = a;
            stack.push(node);
        } else {
            BTNode *node = (BTNode *) malloc(sizeof(BTNode));
            node->data = c;
            node->lchild = node->rchild = NULL;
            stack.push(node);
        }
    }
    return stack.top();
}


int main() {
    string a;
    cin >> a;
    BTree tree = createExpressionTree(a);
    expressionPreOrder(tree);
    cout << endl;
    expressionInOrder(tree);
    cout << endl;
    return 0;
}
