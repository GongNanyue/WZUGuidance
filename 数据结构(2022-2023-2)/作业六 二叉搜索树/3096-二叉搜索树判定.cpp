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

int getDigitsCnt(int n) {
    int cnt = 0;
    while (n != 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

BSTree createBSTreeFromGeneralizedList(char s[], int left, int right) {
    if (left > right) {
        return NULL;
    }
    BSTNode *node = (BSTNode *) malloc(sizeof(BSTNode));

    sscanf(&s[left], "%d", &node->data);
    node->lchild = NULL;
    node->rchild = NULL;
    if (left == right) return node;
    int i = left + getDigitsCnt(node->data);
    int count = 0;
    while (i <= right) {
        if (s[i] == '(') {
            count++;
        } else if (s[i] == ')') {
            count--;
        } else if (count == 1 && (s[i] == ',' || i == right)) {
            break;
        }
        i++;
    }
    node->lchild = createBSTreeFromGeneralizedList(s, left + getDigitsCnt(node->data) + 1, i - 1);
    node->rchild = createBSTreeFromGeneralizedList(s, i + 1, right - 1);
    return node;
}

void inOrder(BSTree bt,vector<int> &v){
    if(!bt) return ;
    inOrder(bt->lchild,v);
    v.push_back(bt->data);
    inOrder(bt->rchild,v);
}

int judge(vector<int> &v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            return 0;
        }
    }
    return 1;
}

BSTree createTree(string s){
    stack<BSTree> st;
    BSTree root=(BSTree) malloc(sizeof(BSTNode));
    int j=0;
    int num=0;
    while(isdigit(s[j])){
        num=num*10+s[j]-'0';
        j++;
    }
    root->data=num,root->lchild=NULL,root->rchild=NULL;
    BSTree head=root;
    int t=1;
    int i=j;
    while(i<s.size()){
        if(isdigit(s[i])){
            int number=0;
            root =(BSTree) malloc(sizeof(BSTNode));
            while(isdigit(s[i])){
                number=number*10+s[i]-'0';
                i++;
            }
            root->data=number;
            root->lchild=root->rchild=NULL;
            if(t==1){
                st.top()->lchild=root;
            }
            else{
                st.top()->rchild=root;
            }
            t=1;
            continue;
        }
        else if(s[i]=='('){
            st.push(root);
        }
        else if(s[i]==')'){
            st.pop();
        }
        else{
            t=-1;
        }
        i++;
    }
    return head;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    string s;
    getline(cin, s);

    BSTree root = createTree(s);
    vector<int>  arr;
    inOrder(root,arr);
    if (judge(arr))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}

