def getPrimes(n):
    vis = [False for i in range(n + 1)]
    primes = []
    for i in range(2, n + 1):
        if not vis[i]:
            primes.append(i)
        for j in primes:
            if i * j > n:
                break
            vis[i * j] = True
            if i % j == 0:
                break
    return primes


def count(a):
    p = getPrimes(2000)
    ans = 0
    for i in p:
        if i >= a - i:
            break
        if a - i in p and a - i != i:
            ans += 1
    return ans


while True:
    a = int(input())
    if a == 0:
        break
    print(count(a))
