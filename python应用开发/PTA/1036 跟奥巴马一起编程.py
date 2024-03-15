c = input().split()
n = int(c[0])
c = c[1]
print(c * n)
for i in range(int(n / 2 + 0.5) - 2):
    print(c + " " * (n - 2) + c)
print(c * n)
