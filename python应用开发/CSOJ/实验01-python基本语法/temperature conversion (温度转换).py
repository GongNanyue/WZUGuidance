def trans(n):
    return (n - 32) * 5 / 9


for i in range(0, 320, 20):
    print("{}    {}".format(i, int(trans(i))))