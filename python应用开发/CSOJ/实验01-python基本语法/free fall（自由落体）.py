x, n = map(float, input().split())
n = int(n)
res = 0.0
for i in range(n):
    if i == 0:
        res += x
    else:
        res += 2 * x
    x /= 2
print("{:.6f}".format(res))