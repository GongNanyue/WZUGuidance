a = list(map(int,input().split()))
a = a[1:]
s = set()
for i in range(0,len(a)):
    for j in range(i + 1,len(a)):
        s.add(a[i] * 10 + a[j])
        s.add(a[j] * 10 + a[i])

print(sum(s))
