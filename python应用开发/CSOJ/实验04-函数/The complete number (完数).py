def fac(a):
    ans = []
    for i in range(1, a):
        if a % i == 0:
            ans.append(i)
    return ans


for i in range(1, 1001):
    if sum(fac(i)) == i:
        print(f"{i} its factors are ", end='')
        print(' '.join(map(str, fac(i))))