while True:
    try:
        a ,b = input().split()
        idx = 0
        f = True
        i = 0
        while i < len(a):
            if a[i] == b[idx]:
                idx += 1
                i += 1
            else:
                idx += 1
            if i != len(a) and  idx == len(b):
                f = False
                break
        if f:
            print("Yes")
        else:
            print("No")
    except IOError:
        break
