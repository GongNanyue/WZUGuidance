n = int(input())
lst = []
for i in range(n):
    lst.append(input().split())
    lst[-1][2] = int(lst[-1][2])
lst.sort(key=lambda x: x[2])
print(f"{lst[-1][0]} {lst[-1][1]}")
print(f"{lst[0][0]} {lst[0][1]}")
