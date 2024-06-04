def getCz(n):
    l = set()
    while n > 1:
        if n % 2 == 0:
            n /= 2
            l.add(n)
        else:
            n = (3 * n + 1) // 2
            l.add(n)
    return l


n = int(input())
a = list(map(int, input().split()))
vis = set()
for i in a:
    vis = vis.union(getCz(i))
key = [i for i in a if i not in vis]
key.sort(reverse=True)
print(" ".join(map(str, key)))
