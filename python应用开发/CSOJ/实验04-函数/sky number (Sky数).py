def to16(a):
    ans = 0
    a = hex(a)[2:]
    for i in range(len(a)):
        ans += int(a[i], 16)
    return ans


def to12(a):
    b = ""
    while a > 0:
        b += str(a % 12)
        a //= 12
    b = b[::-1]
    return sum([int(b[i], 12) for i in range(len(b))])


def to10(a):
    a = str(a)
    return sum([int(a[i]) for i in range(len(a))])


t = int(input())
for _ in range(t):
    x = int(input())
    if to10(x) == to12(x) == to16(x):
        print(f"{x} is a Sky Number.")
    else:
        print(f"{x} is not a Sky Number.")