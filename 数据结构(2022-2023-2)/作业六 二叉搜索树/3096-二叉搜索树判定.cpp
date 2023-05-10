
#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
} BSTNode, BTNode, *BSTree, *BTree;


void inOrder(BSTree bt, vector<int> &v) {
    if (!bt) return;
    inOrder(bt->lchild, v);
    v.push_back(bt->data);
    inOrder(bt->rchild, v);
}

int judge(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0;
        }
    }
    return 1;
}

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
    sscanf(s + left, "%d", &parentNode->data);

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

char s[2000010];

int main() {
    
    scanf("%s",s);
    BSTree root = createTree(s,0, strlen(s));
    vector<int> arr;
    inOrder(root, arr);
    if (judge(arr))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}


