def isT(n):
    x = n // 100
    y = n // 10 % 10
    z = n % 10
    return x ** 3 + y ** 3 + z ** 3 == n
for i in range(100, 1000):
    if isT(i):
        print(i)
        