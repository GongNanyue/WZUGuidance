import math

n = int(input())
l= list()
for _ in range(n):
    x, y = map(float, input().split())
    l.append((x, y))
d = [math.sqrt((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2) for x in l for y in l]
print(f"{max(d):.4f}")
