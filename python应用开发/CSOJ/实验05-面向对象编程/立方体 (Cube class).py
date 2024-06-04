class Cube:
    def __init__(self, edge):
        self.edge = edge
        self.volume = 0
        self.area = 0

    def cal_volume(self):
        self.volume = self.edge ** 3

    def cal_area(self):
        self.area = 6 * (self.edge ** 2)

    def __str__(self):
        return f"Volume:{self.volume:.2f}; Area:{self.area:.2f}"

    def display(self):
        print(self.__str__())


if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        edge = float(input())
        obj = Cube(edge)
        obj.cal_volume()
        obj.cal_area()
        print(f"obj{i} {obj}")