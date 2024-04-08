a, b, c, d = input().split()
a = b * a.count(b)
c = d * c.count(d)
print(int(a.zfill(1)) + int(c.zfill(1)))
