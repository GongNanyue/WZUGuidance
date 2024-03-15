n,m = map(int,input().split())
l = list(map(int,input().split()))
for i in l[n - m:]:
    print(i,end=' ')
for i in l[0:n - m]:
    print(i,end=' ')
