t = int(input())
for _ in range(t):
    a,b,c = map(int,input().split())
    if  a + b > c:
        print(f"Case #{_+1}: true")
    else:
        print(f"Case #{_+1}: false")
