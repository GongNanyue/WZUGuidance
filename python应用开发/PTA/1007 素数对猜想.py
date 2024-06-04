def getPrimes(n):
    p = []
    vis = [False for i in range(n + 1)]
    for i in range(2, n + 1):
        if not vis[i]:
            p.append(i)
        for j in p:
            if i * j > n:
                break
            vis[i * j] = True
            if i % j == 0:
                break
    return p


n = int(input())
p = getPrimes(n)
ans = 0
for i in range(len(p) - 1):
    if p[i + 1] - p[i] == 2:
        ans += 1
print(ans)
