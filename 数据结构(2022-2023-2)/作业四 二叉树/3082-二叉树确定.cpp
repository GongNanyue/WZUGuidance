#include <bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef struct Node {
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
} BTNode, *BTree;

void MidOrder(BTNode *node){
    if(node == NULL)return;
    MidOrder(node->lchild);
    cout << node->data;
    MidOrder(node->rchild);
}


void LastOrder(BTNode *node){
    if(node == NULL)return;
    LastOrder(node->lchild);
    LastOrder(node->rchild);
    cout << node->data;
}
BTree createTreeFromFirstMidOrder(string first, string mid) {

    if (first.empty()) {
        return NULL;
    }

    BTNode *node = (BTNode *) malloc(sizeof(BTNode));
    char root = first[0];
    node->data = root;
    node->lchild = node->rchild = NULL;
    int idx = mid.find(root);
    string midLeft = mid.substr(0, idx);
    string midRight = mid.substr(idx + 1, mid.size() - idx);
    int firstBound = 0;
    for (int i = 0; i < midLeft.size(); ++i) {
        firstBound = max(firstBound, (int) first.find(midLeft[i]));
    }

    node->lchild = createTreeFromFirstMidOrder(first.substr(1, firstBound ), midLeft);
    node->rchild = createTreeFromFirstMidOrder(first.substr(firstBound + 1, first.size() - firstBound + 1), midRight);

    return node;
}


int main() {
    string a,b;
    cin >> a>> b;
    BTree tree = createTreeFromFirstMidOrder(a,  b);
    LastOrder(tree);
cout << endl;
    return 0;
}
