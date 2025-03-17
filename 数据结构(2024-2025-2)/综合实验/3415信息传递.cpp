#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        vector<int> T(n+1);
        for(int i = 1; i <= n; i++){
            scanf("%d", &T[i]);
        }
        int ans = n + 1; // 用一个足够大的值初始化答案
        // 状态：0-未访问, 1-正在访问, 2-已处理
        vector<int> state(n+1, 0);
        vector<int> depth(n+1, -1);
        
        for(int i = 1; i <= n; i++){
            if(state[i] == 0){
                int cur = i, d = 0;
                // 记录当前链上访问过的节点
                vector<int> chain;
                while(state[cur] == 0){
                    state[cur] = 1;
                    depth[cur] = d;
                    chain.push_back(cur);
                    d++;
                    cur = T[cur];
                }
                // 当遇到正在访问的节点说明找到了环
                if(state[cur] == 1){
                    int cycleLen = d - depth[cur];
                    ans = min(ans, cycleLen);
                }
                // 将当前链中所有节点标记为已处理
                for(int j = 0; j < chain.size(); j++){
                    state[chain[j]] = 2;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
