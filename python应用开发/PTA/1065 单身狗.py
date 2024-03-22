n = int(input())
mp = dict()
for i in range(n):
    a, b = input().split()
    mp[a] = b
    mp[b] = a

m = int(input())
st = set(input().split())
res = []

for i in st:
    if i not in mp or mp[i] not in st:
        res.append(i)
res.sort()

print(len(res))
for i,x in enumerate(res):
    if i == len(res)-1:
        print(x)
    else:
        print(x, end=' ')
