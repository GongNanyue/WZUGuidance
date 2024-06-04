import re


def legal(a: int) -> bool:
    a = str(a)
    if re.search(r"(62)+", a):
        return False
    if re.search(r"4+", a):
        return False
    return True



while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    ans = 0
    for i in range(n, m + 1):
        if legal(i):
            ans += 1
    print(ans)