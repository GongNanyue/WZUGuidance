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

int main() {
  gets(s);
  BTree tree = preOrderCreate();
  inOrder(tree);
  puts("");
  return 0;
}
