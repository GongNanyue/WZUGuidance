while True:
    n,m = map(int,input().split())
    if n == 0 and m == 0:
        break
    l = list(map(int,input().split()))
    l.append(m)
    l.sort()
    print(' '.join(map(str,l)))
