class Shape:
    def getArea(self):
        pass

    def getVolume(self):
        pass


class Cylinder(Shape):
    def __init__(self, r, h):
        self.r = r
        self.h = h

    def getArea(self):
        return 2 * 3.14 * self.r * self.r + 2 * 3.14 * self.r * self.h

    def getVolume(self):
        return 3.14 * self.r * self.r * self.h


class Ball(Shape):
    def __init__(self, r):
        self.r = r

    def getArea(self):
        return 4.0 * 3.14 * self.r * self.r

    def getVolume(self):
        return 4.0 / 3.0 * 3.14 * self.r * self.r * self.r


class Cuber(Shape):
    def __init__(self, a):
        self.a = a

    def getArea(self):
        return 6 * self.a * self.a

    def getVolume(self):
        return self.a * self.a * self.a


class Cuboid(Shape):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def getArea(self):
        return 2 * (self.a * self.b + self.a * self.c + self.b * self.c)

    def getVolume(self):
        return self.a * self.b * self.c


t = int(input())
for _ in range(t):
    r, h = map(float, input().split())
    cylinder = Cylinder(r, h)
    print(f"{cylinder.getArea():.2f} {cylinder.getVolume():.2f}")

    r = float(input())
    ball = Ball(r)
    print(f"{ball.getArea():.2f} {ball.getVolume():.2f}")

    a = float(input())
    cuber = Cuber(a)
    print(f"{cuber.getArea():.2f} {cuber.getVolume():.2f}")

    a, b, c = map(float, input().split())
    cuboid = Cuboid(a, b, c)
    print(f"{cuboid.getArea():.2f} {cuboid.getVolume():.2f}")