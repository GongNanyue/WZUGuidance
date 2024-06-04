n, m = map(int,input().split())
a = [[] for i in range(m)]
for i in range(m):
    a[i] = list(map(int, input().split()))
b = [0] * n
for i in range(n):
    for j in range(m):
        b[i] += a[j][i]
print(max(b))
ans = []
for i in range(n):
    if b[i] == max(b):
        ans.append(i + 1)
print(" ".join(map(str, ans)))
