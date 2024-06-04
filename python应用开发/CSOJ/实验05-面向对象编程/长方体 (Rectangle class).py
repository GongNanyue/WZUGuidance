class Cuboid:
    def __init__(self, length, width, height):
        self.length = length
        self.width = width
        self.height = height

    def get_bottom_area(self):
        return self.length * self.width

    def get_volume(self):
        return self.get_bottom_area() * self.height


if __name__ == "__main__":
    l , w, h = map(int, input().split())
    cuboid = Cuboid(l, w, h)
    print(cuboid.get_bottom_area())
    print(cuboid.get_volume())

