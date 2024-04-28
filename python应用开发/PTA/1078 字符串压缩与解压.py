op = input()
if op == "C":
    s = input()
    res = ""
    i, j = 0, 0
    while i < len(s):
        while j < len(s) and s[j] == s[i]:
            j += 1
        if j - i > 1:
            res += str(j - i) + s[i]
        else:
            res += s[i]
        i = j
    print(res)
elif op == "D":
    s = input()
    res = ""
    i = 0
    while i < len(s):
        num = ""
        while i < len(s) and s[i].isdigit():
            num += s[i]
            i += 1
        if num == "":
            num = "1"
        res += s[i] * int(num)
        i += 1
    print(res)
