t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [[] for i in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))
    b = [[a[i][j] for i in range(n)] for j in range(m)]
    for i in range(m):
        print(" ".join(map(str,b[i])))
    print("")
