#include <cstdio>
#include <algorithm>
using namespace std;
const int NMAX = 1000000 + 5;
struct Node {
    int value;
    int sum;
    int maxPref;
};
Node leftStack[NMAX];
int leftTop = 0;
int rightStack[NMAX];
int rightTop = 0;
int main(){
    int Q;
    scanf("%d", &Q);
    char op[5];
    while(Q--){
        scanf("%s", op);
        if(op[0]=='I'){
            int x;
            scanf("%d", &x);
            if(leftTop == 0){
                leftStack[leftTop].value = x;
                leftStack[leftTop].sum = x;
                leftStack[leftTop].maxPref = x;
            } else {
                leftStack[leftTop].value = x;
                leftStack[leftTop].sum = leftStack[leftTop-1].sum + x;
                leftStack[leftTop].maxPref = max(leftStack[leftTop-1].maxPref, leftStack[leftTop].sum);
            }
            leftTop++;
        } else if(op[0]=='D'){
            if(leftTop > 0){
                leftTop--;
            }
        } else if(op[0]=='L'){
            if(leftTop > 0){
                rightStack[rightTop++] = leftStack[leftTop-1].value;
                leftTop--;
            }
        } else if(op[0]=='R'){
            if(rightTop > 0){
                int x = rightStack[--rightTop];
                if(leftTop == 0){
                    leftStack[leftTop].value = x;
                    leftStack[leftTop].sum = x;
                    leftStack[leftTop].maxPref = x;
                } else {
                    leftStack[leftTop].value = x;
                    leftStack[leftTop].sum = leftStack[leftTop-1].sum + x;
                    leftStack[leftTop].maxPref = max(leftStack[leftTop-1].maxPref, leftStack[leftTop].sum);
                }
                leftTop++;
            }
        } else if(op[0]=='Q'){
            int k;
            scanf("%d", &k);
            printf("%d\n", leftStack[k-1].maxPref);
        }
    }
    return 0;
}
