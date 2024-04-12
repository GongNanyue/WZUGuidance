import string

a, b = input().split()
if a.isupper():
    print(string.ascii_uppercase.find(a) + 1 + int(b))
else:
    print(- string.ascii_lowercase.find(a) - 1 + int(b))
