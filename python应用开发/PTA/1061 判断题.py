n, m = map(int, input().split())
score = list(map(int, input().split()))
right = list(map(int, input().split()))
for i in range(n):
    stu = list(map(int, input().split()))
    ans = 0
    for j in range(m):
        if stu[j] == right[j]:
            ans += score[j]
    print(ans)
