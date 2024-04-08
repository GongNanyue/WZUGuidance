import collections

n, m = map(int, input().split())
l = set(input().split())
s = [input().split() for _ in range(n)]
stu, obj = 0, 0
for i in s:
    name = i[0]
    cary = i[2:]
    comm = [j for j in cary if j in l]
    if len(comm) > 0:
        print(name, end=': ')
        print(' '.join(comm))
        stu += 1
        obj += len(comm)
print(stu, obj)
