
n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
for i in range(n):
    if i + 1 >= a[i]:
        print(i)
        exit()
print(n)
