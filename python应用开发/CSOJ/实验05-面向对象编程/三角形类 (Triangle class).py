class GeometricObject:
    def __init__(self, color, filled):
        self.color = color
        self.filled = filled


class Triangle(GeometricObject):
    def __init__(self, color, filled, side1=1.0, side2=1.0, side3=1.0):
        super().__init__(color, filled)
        self.side1 = side1
        self.side2 = side2
        self.side3 = side3

    def get_area(self):
        p = (self.side1 + self.side2 + self.side3) / 2
        return (p * (p - self.side1) * (p - self.side2) * (p - self.side3)) ** 0.5

    def get_perimeter(self):
        return self.side1 + self.side2 + self.side3

    def __str__(self):
        return f"Triangle: side1={self.side1} side2={self.side2} side3={self.side3} color={self.color} filled={self.filled}\n" \
               f"Area={self.get_area():.2f}\n" \
               f"Perimeter={self.get_perimeter():.2f}\n"


if __name__ == "__main__":
    a, b, c, color, filled = input().split()
    a, b, c = float(a), float(b), float(c)

    triangle = Triangle(color, filled, a, b, c)
    print(triangle)