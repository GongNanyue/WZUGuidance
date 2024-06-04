import math


class Cylinder:
    def __init__(self, radius, height):
        self.radius = radius
        self.height = height

    def get_volume(self):
        return 3.14 * self.radius ** 2 * self.height


if __name__ == "__main__":
    r, h = map(int, input().split())
    cylinder = Cylinder(r, h)
    print(f"{cylinder.get_volume():.2f}")