#include <bits/stdc++.h>
using namespace std;


typedef struct {
    int *parent;
    int size;
} SNode, *Set;


int findSet(Set S, int x) {
    return S->parent[x] == -1 ? x : S->parent[x] = findSet(S, S->parent[x]);
}

Set createSet(int size) {
    Set set = (Set) malloc(sizeof(SNode));
    set->size = size;
    set->parent = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i)
        set->parent[i] = -1;
    return set;
}


void initSet(Set S) {
    for (int i = 0; i < S->size; ++i)
        S->parent[i] = -1;
}


void unionSet(Set S, int x, int y) {
    int rootX = findSet(S, x);
    int rootY = findSet(S, y);
    if (rootX == rootY)
        return;
    S->parent[rootX] = rootY;
}

void destroySet(Set S) {
    free(S->parent);
    free(S);
}

int main() {
    int n;
    cin >> n;
    Set set = createSet(n);
    initSet(set);
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        unionSet(set, x, y);
    }
    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (findSet(set, a) == findSet(set, b))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    destroySet(set);
    return 0;
}
