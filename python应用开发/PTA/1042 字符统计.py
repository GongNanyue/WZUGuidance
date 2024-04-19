a = input().lower()
d = {i: a.count(i) for i in a if i.isalpha()}
d = sorted(d.items(), key=lambda x: (-x[1], x[0]))
print(d[0][0], d[0][1])
