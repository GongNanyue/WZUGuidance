t = int(input())

p, q = 0, 0
for _ in range(t):
    x, y, a, b = map(int, input().split())
    f1 = (y == x + a)
    f2 = (b == x + a)
    if f1 and not f2:
        q += 1
    elif not f1 and f2:
        p += 1

print(f"{p} {q}")
