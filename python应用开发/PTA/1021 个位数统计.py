from collections import Counter

s = input()
d = Counter(map(int, s))
for ky, vl in sorted(d.items()):
    print(f"{ky}:{vl}")
