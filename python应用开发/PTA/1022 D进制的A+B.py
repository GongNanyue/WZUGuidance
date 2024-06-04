def getNum(n, d):
    ans = ""
    while n > 0:
        ans += str(n % d)
        n = n // d
    ans = "".join(reversed(ans))
    if ans == "":
        ans = "0"
    return ans


a, b, d = map(int, input().split())
print(getNum(a + b, d))
