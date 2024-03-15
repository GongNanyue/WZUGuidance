def isPrime(n):
    if n < 2: return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

t = int(input())
for _ in range(t):
    n = int(input())
    if isPrime(n):
        print("yes")
    else:
        print("no")