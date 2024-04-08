from collections import defaultdict

n = int(input())
d = defaultdict(int)
for i in range(n):
    a, c = input().split()
    a, b = a.split('-')
    c = int(c)
    d[a] += c
d = sorted(d.items(), key=lambda item: item[1], reverse=True)
print(d[0][0], d[0][1])
