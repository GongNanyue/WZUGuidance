def isprime(n):
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


n = int(input())
a = []
for i in range(n):
    a.append(input())
rank = {}
for i in range(n):
    rank[a[i]] = i + 1

k = int(input())
vis = set()
for i in range(k):
    b = input()

    c = rank.get(b)

    if c is None:
        print(f"{b}: Are you kidding?")
        continue
    c = c - 1
    if b in vis:
        print(f"{b}: Checked")
        continue
    if c == 0:
        print(f"{b}: Mystery Award")
    elif isprime(c + 1):
        print(f"{b}: Minion")
    else:
        print(f"{b}: Chocolate")
    vis.add(b)
