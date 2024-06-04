def fac(a):
    ans = 0
    for i in range(1, a):
        if a % i == 0:
            ans += i
    return ans


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if fac(a) == b and fac(b) == a:
        print("YES")
    else:
        print("NO")