def isTra(a, b, c):
    return a ** 2 + b ** 2 == c ** 2


t = int(input())
for _ in range(t):
    x = int(input())
    ans = 0
    for i in range(5, x + 1):
        for j in range(4, i):
            for k in range(3, j):
                if isTra(k, j, i):
                    ans += 1
    print(f"case#{_ + 1}")
    print(ans)