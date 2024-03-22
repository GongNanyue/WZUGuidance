n = int(input())
res = set()
st = set()

for i in range(1, n + 1):
    st.add(i // 2 + i // 3 + i // 5)
    res.add(len(st))
print(len(res))
