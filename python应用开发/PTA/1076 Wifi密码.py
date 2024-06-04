n = int(input())
res = ""
for _ in range(n):
    s = input().split()
    for i in range(4):
        if s[i][2] == "T":
            res += str(ord(s[i][0]) - ord('A') + 1)
print(res)
