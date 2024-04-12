import string

a = input()
up = string.ascii_uppercase + string.ascii_uppercase
lw = string.ascii_lowercase + string.ascii_lowercase
ans = ''
for c in a:
    if c.islower():
        ans += lw[ord(c) - ord('a') + 5]
    elif c.isupper():
        ans += up[ord(c) - ord('A') + 5]
    else:
        ans += c
print(ans)
