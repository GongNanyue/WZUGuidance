import math


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 2):
        if n % i == 0:
            return False
    return True


L, K = map(int, input().split())
s = input()
for i in range(0, L - K + 1):
    a = s[i:i + K]
    if is_prime(int(a)):
        print(a)
        exit(0)
print('404')
