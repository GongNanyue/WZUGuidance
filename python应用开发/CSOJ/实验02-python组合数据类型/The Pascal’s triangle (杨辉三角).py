l = list(map(int, input().split()))
a = [[0 for i in range(max(l))] for j in range(max(l))]
a[0][0] = 1
for i in range(1, max(l)):
    for j in range(0, i+1):
        if j == 0:
            a[i][j] = a[i - 1][j]
        elif j == i:
            a[i][j] = a[i - 1][j - 1]
        else:
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j]
for n in l:
    for i in range(n):
        print(' '.join(map(str,a[i][0:i + 1])))
    print("")
