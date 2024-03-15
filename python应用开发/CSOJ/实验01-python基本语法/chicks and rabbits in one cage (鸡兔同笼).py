n = int(input())
if n % 2 == 1:
    print("0 0")
    exit(0)
y = n // 4
x = n % 4 // 2
print(f"{x + y}", end=" ")
x = n // 2
y = n % 2 // 4
print(f"{x + y}")