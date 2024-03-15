def isT(n):
    x = n // 100
    y = n // 10 % 10
    z = n % 10
    return x ** 3 + y ** 3 + z ** 3 == n


t = int(input())
for _ in range(t):
    f = False
    a, b = map(int, input().split())
    for i in range(a, b + 1):
        if isT(i):
            f = True
            print(i, end=' ')
    if not f:
        print('no',end='')
    print()