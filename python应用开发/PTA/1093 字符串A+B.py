a = input()
b = input()
st = set()
for c in a:
    if c not in st:
        print(c, end='')
        st.add(c)
for c in b:
    if c not in st:
        print(c, end='')
        st.add(c)
