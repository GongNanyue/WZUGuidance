p = input().split(" ")
a, b, c = map(int, p[0].split("."))
x, y, z = map(int, p[1].split("."))

c += a * 17 * 29 + b * 29
z += x * 17 * 29 + y * 29

if c > z:
    c -= z
    print(f"-{c // (17 * 29)}.{c % (17 * 29) // 29}.{c % 29}")
else:
    z -= c
    print(f"{z // (17 * 29)}.{z % (17 * 29) // 29}.{z % 29}")
