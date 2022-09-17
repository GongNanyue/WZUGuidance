#include <bits/stdc++.h>

using namespace std;
int a[99];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m;
        int maxv = -10000, val;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &val);
            if (maxv < val)maxv = val;
        }
        printf("%d\n", maxv);


    }
    return 0;
}
