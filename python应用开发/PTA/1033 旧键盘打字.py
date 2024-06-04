a = input().upper()
b = input()
if a.find('+') != -1:
    for i in b:
        if i.isupper():
            pass
        elif i.upper() in set(a):
            pass
        else:
            print(i, end='')
else:
    for i in b:
        if i.upper() in set(a):
            pass
        else:
            print(i, end='')
