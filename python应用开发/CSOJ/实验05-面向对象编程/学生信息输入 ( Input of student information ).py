class Student:
    def __init__(self, id, name, gender, c, m, e):
        self.id = id
        self.name = name
        self.gender = gender
        self.C = c
        self.M = m
        self.E = e
        self.sum = c + m + e
        self.avg = self.sum / 3


if __name__ == "__main__":
    id, name, gender, C, M, E = input().split()
    C, M, E = map(float, [C, M, E])
    student = Student(id, name, gender, C, M, E)
    print(
        f"{student.id} {student.name} {student.gender} {student.C:.2f} {student.M:.2f} {student.E:.2f} {student.avg:.2f} {student.sum:.2f}")