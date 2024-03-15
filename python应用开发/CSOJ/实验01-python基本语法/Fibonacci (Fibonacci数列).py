lst = [0, 1]
for i in range(2, 50):
    lst.append(lst[i - 1] + lst[i - 2])

n = int(input())
while n != -1:
    print(lst[n])
    n = int(input())
    