a, b, c, d = map(float, input().split())
print("{:.2f}".format(((a - c) ** 2 + (b - d) ** 2) ** 0.5))