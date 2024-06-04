import heapq
import math

n = int(input())
a = list(map(int, input().split()))
heapq.heapify(a)
while len(a) > 1:
    x = heapq.heappop(a)
    y = heapq.heappop(a)
    heapq.heappush(a,(x + y)/2 )
print(math.floor(heapq.heappop(a)))
