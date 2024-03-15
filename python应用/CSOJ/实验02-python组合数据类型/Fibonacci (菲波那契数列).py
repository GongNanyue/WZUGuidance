t = int(input())
l = list()
for _ in range(t):
    n = int(input())
    l.append(n)
fi = [0 for i in range(max(10,max(l) + 1))]
fi[1] = 1
for i in range(2, max(l) + 1):
    fi[i] = fi[i-1] + fi[i-2]
for i in l:
    print(fi[i])
