#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef struct {
    KeyType value;
    int weight;
} Node;
typedef struct HTNode {
    KeyType value; //节点数值
    int weight;  //节点权
    HTNode *lchild;
    HTNode *rchild;
    int depth;

    bool operator<(const HTNode &a) const {
        return weight < a.weight || (weight == a.weight && value < a.value);
    }
} HTNode, *HuffmanTree;
typedef HuffmanTree ElementType;
typedef struct {
    ElementType *data; //数据
    int size;            //大小
    int capacity;        //容量
} HNode, *Heap;

int parent(int u) {
    return u / 2;
}

int left(int u) {
    return u * 2;
}

int right(int u) {
    return u * 2 + 1;
}

void swap(Heap H, int u, int v) {
    swap(H->data[u], H->data[v]);
}

void heapify(Heap H, int i) {
    int smallest = i;
    if (left(i) <= H->size && *H->data[left(i)] < *H->data[smallest])
        smallest = left(i);
    if (right(i) <= H->size && *H->data[right(i)] < *H->data[smallest])
        smallest = right(i);
    if (smallest != i) {
        swap(H, i, smallest);
        heapify(H, smallest);
    }

}

ElementType front(Heap H) {
    return H->data[1];
}

void push(Heap H, ElementType x) {
    H->data[++H->size] = x;
    int i = H->size;
    while (i >= 2 && *(H->data[i]) < *(H->data[parent(i)])) {
        swap(H, i, parent(i));
        i = parent(i);
    }

}

void pop(Heap H) {
    swap(H, 1, H->size);
    --H->size;
    heapify(H, 1);
}

Heap createHeap(int capacity) {
    Heap heap = (Heap) malloc(sizeof(HTNode));
    heap->size = 0;
    heap->capacity = capacity;
    heap->data = (ElementType *) malloc(sizeof(ElementType) * (capacity + 1));
    return heap;
}

void initHeap(Heap H, Node data[], int n) {
    //H->data = (ElementType *) malloc(sizeof(ElementType) * (n + 1));
    //在createHeap 创建 H的时候就已经分配好内存了
    //H->capacity = n;
    //H 已经初始化好capacity
    H->size = n;
    for (int i = 1; i <= n; ++i) {
        H->data[i] = (HTNode *) malloc(sizeof(HTNode));
        H->data[i]->weight = data[i].weight;
        H->data[i]->value = data[i].value;
        H->data[i]->lchild = H->data[i]->rchild = NULL;
        H->data[i]->depth = 0;

    }

    for (int i = H->size / 2; i >= 1; --i)
        heapify(H, i);
}

HuffmanTree createHuffmanTree(Node data[], int n) {

    Heap heap = createHeap(n);
    initHeap(heap, data, n);
    while (heap->size > 1) {
        HuffmanTree a = front(heap);
        pop(heap);
        HuffmanTree b = front(heap);
        pop(heap);
        HTNode *nodePointer = (HTNode *) malloc(sizeof(HTNode));
        nodePointer->value = std::min(a->value, b->value);
        nodePointer->weight = a->weight + b->weight;
        nodePointer->depth = std::max(a->depth, b->depth) + 1;
        nodePointer->lchild = a;
        nodePointer->rchild = b;
        push(heap, nodePointer);
    }
    return front(heap);
}

void huffmanCode(HuffmanTree HT, int code[], int depth) {
    if (HT == NULL) return;
    if (HT->lchild == NULL && HT->rchild == NULL) {
        printf("%d:", HT->value);
        for (int i = 0; i < depth; ++i)
            putchar(code[i] + '0');
        puts("");
    }
    if (HT->lchild != NULL) {
        code[depth] = 0;
        huffmanCode(HT->lchild, code, depth + 1);

    }
    if (HT->rchild != NULL) {
        code[depth] = 1;
        huffmanCode(HT->rchild, code, depth + 1);

    }
}

void initDepth(HuffmanTree HT, int depth) {
    if (HT == NULL) {
        return;
    }
    HT->depth = depth;
    initDepth(HT->lchild, depth + 1);
    initDepth(HT->rchild, depth + 1);
}

int myGetWPL(HuffmanTree HT) {
    if (HT->lchild == NULL && HT->rchild == NULL)
        return HT->depth * HT->weight;

    int res = 0;

    if (HT->lchild != NULL)
        res += myGetWPL(HT->lchild);

    if (HT->rchild != NULL)
        res += myGetWPL(HT->rchild);
    return res;

}

int getWPL(HuffmanTree HT) {
    initDepth(HT, 0);
    return myGetWPL(HT);
}


int main() {
    int n;
    cin >> n;
    Node data[n+1];
    for (int i = 1; i <=n; ++i)
        cin >> data[i].value >> data[i].weight;

    HuffmanTree  tree = createHuffmanTree(data,n);
    cout << getWPL(tree) << endl;


    return 0;
}
