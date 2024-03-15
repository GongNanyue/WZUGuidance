import statistics

t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    l = l[1:]
    print(f"{statistics.mean(l):.3f} {statistics.pstdev(l):.3f}")
