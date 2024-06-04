import math


class Circle:
    def __init__(self, x=0, y=0, r=1):
        self.x = x
        self.y = y
        self.radius = r

    def cal_diameter(self):
        return 2 * self.radius

    def cal_area(self):
        return 3.14 * self.radius * self.radius

    def cal_perimeter(self):
        return 2 * 3.14 * self.radius

    def output(self):
        print(f"Center=({self.x:.0f},{self.y:.0f}) and Radius={self.radius:.0f}\n"
              f"Diameter={self.cal_diameter():.0f}\n"
              f"Area={self.cal_area():.1f}\n"
              f"Perimeter={self.cal_perimeter():.1f}")


if __name__ == "__main__":
    x, y, r = map(float, input().split())
    circle = Circle(x, y, r)
    circle.output()