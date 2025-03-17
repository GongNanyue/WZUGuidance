#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

const int MAX_DIM = 1600;
const int INF = 0x3f3f3f3f;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);
        char maze[MAX_DIM][MAX_DIM];
        for (int i = 0; i < n; i++){
            scanf("%s", maze[i]);
        }
        int sx = -1, sy = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(maze[i][j] == 'S'){
                    sx = i;
                    sy = j;
                    break;
                }
            }
            if(sx != -1) break;
        }
        // 使用静态二维数组记录每个模状态首次出现的绝对坐标
        // 如果未访问，则记录为INF
        static int visx[MAX_DIM][MAX_DIM];
        static int visy[MAX_DIM][MAX_DIM];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                visx[i][j] = INF;
                visy[i][j] = INF;
            }
        }
 
        queue< pair<int,int> > q;
        q.push( make_pair(sx, sy) );
        // 初始状态的余数组状态为 (sx, sy)（由于 0 <= sx < n, 0 <= sy < m）
        visx[sx][sy] = sx;
        visy[sx][sy] = sy;
 
        bool infinite = false;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
 
        while(!q.empty() && !infinite){
            pair<int,int> cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            for (int k = 0; k < 4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                int rx = ((nx % n) + n) % n; // \((nx \bmod n + n) \bmod n\)
                int ry = ((ny % m) + m) % m; // \((ny \bmod m + m) \bmod m\)
                if(maze[rx][ry]=='#') continue;
                // 如果当前模状态未被访问过，记录绝对坐标并入队
                if(visx[rx][ry] == INF){
                    visx[rx][ry] = nx;
                    visy[rx][ry] = ny;
                    q.push(make_pair(nx, ny));
                } else {
                    // 如果已经访问过但绝对坐标不同，则可以无限延伸
                    if(visx[rx][ry] != nx || visy[rx][ry] != ny){
                        infinite = true;
                        break;
                    }
                }
            }
        }
 
        if(infinite)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
