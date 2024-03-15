while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    l = [i for i in range(n)]
    idx = 0
    while len(l) > 1:
        idx = (idx + m - 1) % len(l)
        l.pop(idx)
        idx = idx % len(l)

    print(f"{l[0] + 1}")
