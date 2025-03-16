#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    int t, num, x, tmp, teamID;
    int scenario = 1;
    while(scanf("%d", &t)==1 && t){
        vector<int> teamOf(1000000, -1);
        vector<queue<int> > teamQ(t);
        queue<int> groupQ;
        vector<bool> inGroup(t, false);
        for(int i=0; i<t; i++){
            scanf("%d", &num);
            for(int j=0; j<num; j++){
                scanf("%d", &tmp);
                teamOf[tmp] = i;
            }
        }
        char op[20];
        printf("Scenario #%d\n", scenario++);
        while(scanf("%s", op)==1){
            if(strcmp(op,"STOP")==0) break;
            if(strcmp(op,"ENQUEUE")==0){
                scanf("%d", &x);
                teamID = teamOf[x];
                if(!inGroup[teamID]){
                    groupQ.push(teamID);
                    inGroup[teamID] = true;
                }
                teamQ[teamID].push(x);
            } else {
                teamID = groupQ.front();
                int front = teamQ[teamID].front();
                teamQ[teamID].pop();
                printf("%d\n", front);
                if(teamQ[teamID].empty()){
                    groupQ.pop();
                    inGroup[teamID] = false;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
