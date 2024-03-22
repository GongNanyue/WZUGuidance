def getFriendNum(n):
    res = 0
    while n > 0:
        res += n % 10
        n = n // 10
    return res


st = set()
n = int(input())
a = list(map(int, input().split()))
for i in a:
    st.add(getFriendNum(i))
print(len(st))
print(" ".join(str(i) for i in sorted(st)   ))
