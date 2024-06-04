import datetime

n = int(input())
for _ in range(n):
    a, b, c = map(int, input().split('/'))
    x = datetime.datetime(a, b, c)
    y = datetime.datetime(a, 1, 1)
    print((x - y).days + 1)