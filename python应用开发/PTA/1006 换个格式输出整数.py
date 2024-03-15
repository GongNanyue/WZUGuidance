n = input()
n = "0" * (3 - len(n)) + n
l = list(map(int, n))
res = "B" * l[0] + "S" * l[1]
res += "".join([str(i) for i in range(1,l[2] +1)])
print(res)

