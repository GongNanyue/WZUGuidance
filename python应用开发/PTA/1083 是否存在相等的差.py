n = int(input())
l = list(map(int, input().split()))
mp = dict()
for i in range(len(l)):
    if abs(l[i] - (i + 1)) in mp:
        mp[abs(l[i] - (i + 1))] += 1
    else:
        mp[abs(l[i] - (i + 1))] = 1

for x in reversed(sorted(mp.keys())):
    if mp[x] >= 2:
        print(x, mp[x])
