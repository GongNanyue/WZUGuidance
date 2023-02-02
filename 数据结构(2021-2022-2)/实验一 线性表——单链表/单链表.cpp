#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int ElementType;
typedef struct Node {
  ElementType data;
  struct Node *next;
} Node, *LinkList;

int getLength(LinkList L) {
  int cnt = 0;
  Node *p = L->next;
  while (p) {
    ++cnt;
    p = p->next;
  }
  return cnt;
}

void printList(LinkList L) {
  Node *p = L->next;
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
  puts("");
}

LinkList createList() {
  LinkList l = malloc(sizeof(Node));
  l->next = NULL;
  return l;
}
void destroyList(LinkList L) {
  Node *p = L, *q = L->next;
  free(L);
  while (q) {
    p = q;
    q = q->next;
    free(p);
  }

}
void clearList(LinkList L) {
  Node *p = L, *q = L->next;
  while (q) {
    p = q;
    q = q->next;
    free(p);
  }
  L->next = NULL;
}

int delNode2(LinkList L, int i, ElementType *px) {
  Node *p = L;
  --i;
  while (p->next && i) {
    p = p->next;
    --i;
  }
  if (!p->next)return 0;
  Node *q = p->next;
  p->next = q->next;
  *px = q->data;
  free(q);
  return 1;
}
Node *findPrevious(LinkList L, ElementType x) {
  Node *p = L;
  while (p->next && p->next->data != x) {
    p = p->next;
  }
  return p;
}
int delNode1(LinkList L, ElementType x) {
  Node *p = findPrevious(L, x), *q = p->next;
  if (!q)return 0;
  p->next = q->next;
  free(q);
  return 1;
}
Node *locate(LinkList L, int i) {
  Node *p = L;
  while (p && i) {
    p = p->next;
    --i;
  }
  if (p == L)return NULL;
  return p;
}
Node *find(LinkList L, ElementType x) {
  Node *p = L->next;
  while (p && p->data != x)
    p = p->next;
  return p;
}
void insertHead(LinkList L, ElementType x) {
  Node *p = (Node *) malloc(sizeof(Node));
  p->data = x;
  p->next = L->next;
  L->next = p;
}

void insertTail(LinkList L, ElementType x) {
  Node *p = L;
  while (p->next)
    p = p->next;
  Node *q = (Node *) malloc(sizeof(Node));
  q->data = x;
  q->next = p->next;
  p->next = q;
}

int insertList(LinkList L, int i, ElementType x) {
  Node *p = L;
  --i;
  while (p->next && i) {
    p = p->next;
    --i;
  }
  if (i) return 0;
  Node *q = (Node *) malloc(sizeof(Node));
  q->data = x;
  q->next = p->next;
  p->next = q;
  return 1;
}
