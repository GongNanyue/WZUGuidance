n = int(input())
d = {y: [x, z] for _ in range(n) for x, y, z in [input().split()]}
n = int(input())
l = map(lambda i: f"{d[i][0]} {d[i][1]}", input().split())
print("\n".join(l))
