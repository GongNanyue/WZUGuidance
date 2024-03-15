
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(f"{sum(a) / n:.2f}") # get mean of a
