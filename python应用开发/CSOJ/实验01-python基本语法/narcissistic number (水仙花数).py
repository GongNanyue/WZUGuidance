a = int(input())
x = a // 100
y = a // 10 % 10
z = a % 10
if x ** 3 + y ** 3 + z ** 3 == a:
    print('Yes')
else:
    print('No')