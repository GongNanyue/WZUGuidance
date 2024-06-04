num = [["tret"] + "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec".split(", "),
       ["???"] + "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou".split(", ")]

t = int(input())
for _ in range(t):
    n = input()
    if n.isdigit():
        n = int(n)
        a, b = divmod(n, 13)
        if a == 0 and b == 0:
            print("tret")
        elif a == 0:
            print(num[0][b])
        elif b == 0:
            print(num[1][a])
        else:
            print(num[1][a], num[0][b])
    else:
        if n.find(" ") == -1:
            if n in num[0]:
                print(num[0].index(n))
            else:
                print(num[1].index(n) * 13)
        else:
            a, b = n.split()
            print(num[1].index(a) * 13 + num[0].index(b))
