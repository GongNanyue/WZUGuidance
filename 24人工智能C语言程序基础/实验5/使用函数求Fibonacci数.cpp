
int fib( int n ){
    int a=1,b=1,c=1,i=0;
    for(i=2;i<n;i++){
        c=b;
        b=a;
        a=b+c;
    }
    return a;
}
