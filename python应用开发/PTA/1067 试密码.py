pwd, n = input().split()
n = int(n)
f = False

while True:
    s = input()
    if n == 0:
        print("Account locked")
        break
    if s == '#':
        break

    if s == pwd:
        print("Welcome in")
        break
    else:
        print(f"Wrong password: {s}")
    n -= 1
