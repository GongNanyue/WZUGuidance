def dec_to_base(n, r):
    conversion = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    if n < r:
        return conversion[n]
    else:
        a, b = divmod(n, r)
        return dec_to_base(a, r) + conversion[b]


while True:
    try:
        x, y = map(int, input().split())
        if x < 0:
            x = -x
            print("-" + dec_to_base(x, y))
        else:
            print(dec_to_base(x, y))
    except EOFError:
        break
