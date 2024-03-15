import functools
import statistics

l = list(map(int, input().split()))
l = l[1:]
a1, a2, a3, a4, a5 = 0, [], 0, [], 0
for i in l:
    if i % 2 == 0 and i % 5 == 0:
        a1 += i
    if i % 5 == 1:
        a2.append(i)
    if i % 5 == 2:
        a3 += 1
    if i % 5 == 3:
        a4.append(i)
    if i % 5 == 4:
        a5 = max(a5, i)
for i in range(len(a2)):
    a2[i] = (-1) ** (i) * a2[i]
if a2 == []:
    a2 = 'N'
else:
    a2 = sum(a2)
if a4 != []:
    a4 = statistics.mean(a4)
    a4 = round(a4, 1)
else:
    a4 = 'N'

if a1 == 0:
    a1 = 'N'
if a3 == 0:
    a3 = 'N'
if a5 == 0:
    a5 = 'N'
print(f"{a1} {a2} {a3} {a4} {a5}")
