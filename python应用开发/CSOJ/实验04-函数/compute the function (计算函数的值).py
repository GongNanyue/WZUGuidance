import sys

sys.setrecursionlimit(10000000)
def f(a, b):
    if a < 0:
        return a + b
    else:
        return f(a - 1, a + b) + a / b


t = int(input())
for _ in range(t):
    x, y = map(float, input().split())
    print(f"{f(x, y):.2f}")