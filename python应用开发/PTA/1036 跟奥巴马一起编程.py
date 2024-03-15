c = input().split()
n = int(c[0])
c = c[1]


print(c * n)
for i in range(n // 2 + n % 2 - 2):
    print(c + " " * (n - 2) + c)
print(c * n)
