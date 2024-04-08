n = int(input())
l = list(map(int, input().split()))
for k in l:
    ans = True
    for i in range(1, 11):
        if int(str(i * (k ** 2))[-len(str(k)):]) == k:
            print(i, i * (k ** 2))
            ans = False
            break
    if ans:
        print("No")
