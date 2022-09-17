#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        int i,j,m;
        i=0,j=1;
        n=n-2;
        while(n--){
            m=j,j=i+j,i=m;
        }
        printf("%d\n",i+j);
    }
    return 0;
}


