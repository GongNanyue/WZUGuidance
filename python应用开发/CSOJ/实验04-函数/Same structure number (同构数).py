def isCon(a: int) -> bool:
    b = str(a * a)
    a = str(a)
    return b.endswith(a)


res = []
for i in range(1, 100):
    if isCon(i):
        res.append(i)
print(' '.join(map(str, res)))