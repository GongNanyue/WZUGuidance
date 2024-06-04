n = input()
n = "0" * (4 - len(n)) + n
if n == "".join(reversed(n)):
    print(f"{n} - {n} = 0000")
    exit(0)

while True:
    n = "".join(sorted(n, reverse=True))
    m = "".join(reversed(n))
    d = int(n) - int(m)
    dd = str(d)
    dd = "0" * (4 - len(dd)) + dd
    print(f"{n} - {m} = {dd}")
    if d == 6174:
        break
    n = dd
