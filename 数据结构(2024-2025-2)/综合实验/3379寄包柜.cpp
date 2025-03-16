#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    vector<vector<int> > mail(n+1);
    for(int i=0;i<q;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int idx,pos,k;
            scanf("%d%d%d",&idx,&pos,&k);
            if((int)mail[idx].size() < pos) mail[idx].resize(pos,0);
            mail[idx][pos-1] = k;
        } else {
            int idx,pos;
            scanf("%d%d",&idx,&pos);
            printf("%d\n",mail[idx][pos-1]);
        }
    }
    return 0;
}
