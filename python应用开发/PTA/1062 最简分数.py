import math
from fractions import *

a = input().split()
a, b, k = Fraction(a[0]), Fraction(a[1]), int(a[2])
if a > b:
    a, b = b, a
ans = []
for i in range(0, k + 1):
    if math.gcd(i, k) == 1:
        c = Fraction(i, k)
        if a < c < b:
            ans.append(c)
print(" ".join(map(str, ans)))
