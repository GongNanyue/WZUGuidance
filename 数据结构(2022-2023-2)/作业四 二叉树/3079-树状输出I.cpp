#include <bits/stdc++.h>

using namespace std;
typedef char ElementType;
typedef struct Node {
  ElementType data;
  struct Node *lchild;
  struct Node *rchild;
} BTNode, *BTree;

void leafNode(BTree rt) {
  if (rt->lchild == NULL && rt->rchild == NULL)
    putchar(rt->data);
  if (rt->lchild != NULL)
    leafNode(rt->lchild);
  if (rt->rchild != NULL)
    leafNode(rt->rchild);
}

int getNum(BTree rt) {
  if (rt == NULL)return 0;
  return getNum(rt->lchild) + getNum(rt->rchild) + 1;
}

void preOrderExt(BTree bt) {
  if (bt == NULL)
    putchar('.');
  else {
    putchar(bt->data);
    preOrderExt(bt->lchild);
    preOrderExt(bt->rchild);
  }
}

char s[1000];
int idx;

BTNode *preOrderCreate() {
  BTNode *node = (BTNode *) malloc(sizeof(BTNode));
  if (s[idx] == '.') {
    node = NULL;
    ++idx;
  } else {
    node->data = s[idx++];
    node->lchild = preOrderCreate();
    node->rchild = preOrderCreate();
  }
  return node;
}

void inOrder(BTree bt) {
  if (!bt)return;
  inOrder(bt->lchild);
  printf("%c", bt->data);
  inOrder(bt->rchild);
}

void treeOut1(BTree bt, int n) {
  if (bt == NULL)return;
  treeOut1(bt->rchild, n + 1);
  for (int i = 0; i < n; ++i)
    putchar('-');
  putchar(bt->data);
  putchar('\n');

  treeOut1(bt->lchild, n + 1);
}

int main() {
  gets(s);
  BTree tree = preOrderCreate();
  treeOut1(tree,0);
  return 0;
}
