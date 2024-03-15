t = int(input())
for _ in range(t):

    n = int(input())
    l = [[0 for i in range(n)] for j in range(n)]
    idx = 1
    for j in range(0, n):
        for i in range(0, n - j):
            l[i][j] = idx;
            idx += 1;
    for i in range(0,n):
        for j in range(0,n - i ):
            print(f"{l[i][j]}",end=' ')
        print("")
