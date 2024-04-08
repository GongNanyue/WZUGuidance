import collections

s = "".join([c for c in input() if c in "PATest"])
d = collections.Counter(s)
idx = 0
p = "PATest"
while len(d) > 0:
    for c in p:
        if d[c] > 0:
            print(c, end='')
            d[c] -= 1
            if d[c] == 0:
                d.pop(c)
