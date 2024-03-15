n = int(input())
for i in range(n // 2):
    for j in range(n // 2 - i):
        print('-', end='')
    for j in range(2 * i + 1):
        print('*', end='')
    for j in range(n // 2 - i):
        print('-', end='')
    print()
print('*' * n)
for i in range(n // 2):
    for j in range(i + 1):
        print('-', end='')
    for j in range(n - 2 * (i + 1)):
        print('*', end='')
    for j in range(i + 1):
        print('-', end='')
    print()