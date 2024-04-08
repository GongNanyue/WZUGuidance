def check(a: dict[str, int], b: dict[str, int]):
    for x, y in b.items():
        if x not in a:
            return False
        if y > a[x]:
            return False
    return True


import collections

a = collections.Counter(input())
b = collections.Counter(input())
if check(a, b):
    print("Yes", end=' ')
    ans = 0
    for x, y in a.items():
        ans += y - b[x]
    print(ans)
else:
    print("No", end=' ')
    ans = 0
    for x, y in b.items():
        ans += max(0,y - a.get(x, 0))
    print(ans)
