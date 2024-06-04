import functools


def legal(a):
    b = str(a)
    s = functools.reduce(lambda x, y: int(x) + int(y), b, 0)
    return a % s == 0
n = int(input())
for i in range(10,n + 1):
    if legal(i):
        print(i)