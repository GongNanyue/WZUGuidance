#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int K, N, M;
    cin >> K >> N >> M;
    vector<int> cows(K);
    for (int i = 0; i < K; i++){
        cin >> cows[i];
        // 注意，牧场编号从1开始
    }
    // 建图，节点编号1~N
    vector<vector<int> > adj(N+1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // 每个节点被多少个奶牛能够到达
    vector<int> cnt(N+1, 0);
    // 对每一只奶牛进行BFS搜索
    for (int i = 0; i < K; i++){
        int start = cows[i];
        vector<bool> visited(N+1, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()){
            int u = q.front();
            q.pop();
            // 记录此奶牛可以到达u
            cnt[u]++;
            for (int j = 0; j < (int)adj[u].size(); j++){
                int v = adj[u][j];
                if (!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++){
        if(cnt[i] == K) ans++;
    }
    cout << ans << endl;
    return 0;
}
