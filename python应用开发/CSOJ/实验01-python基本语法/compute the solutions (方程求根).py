a, b, c = map(float, input().split())
delta = b**2 - 4*a*c
if delta < 0:
    print("no")
elif delta ==0:
    x = -b/(2*a)
    print("{:0.2f}".format(x))
else:
    x1 = (-b + delta**0.5)/(2*a)
    x2 = (-b - delta**0.5)/(2*a)
    print("{:0.2f} {:0.2f}".format(x1, x2))