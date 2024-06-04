import re

t = int(input())
for _ in range(t):
    s = input()
    if not re.match(r'.{6,}$', s):
        print("Your password is tai duan le.")
    elif not re.match(r'[a-zA-Z0-9.]{6,}$', s):
        print("Your password is tai luan le.")
    elif re.match(r'^[a-zA-z.]+$', s):
        print("Your password needs shu zi.")
    elif re.match(r'^[0-9.]+$', s):
        print("Your password needs zi mu.")
    else:
        print("Your password is wan mei.")
