import math

n = int(input())
lst: list[(str, int, int)] = []
for i in range(n):
    x, y, z = input().split()
    y = int(y)
    z = int(z)
    lst.append((x, y, z))
lst = sorted(lst, key=lambda t: math.sqrt(t[1] ** 2 + t[2] ** 2))
print(f"{lst[0][0]} {lst[-1][0]}")
