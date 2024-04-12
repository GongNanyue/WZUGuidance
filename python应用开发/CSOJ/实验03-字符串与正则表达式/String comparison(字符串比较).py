t = int(input())
for _ in range(t):
    a = input()
    b = input()
    for i in range(min(len(a), len(b))):
        if a[i] != b[i]:
            print(ord(a[i]) - ord(b[i]))
            break
