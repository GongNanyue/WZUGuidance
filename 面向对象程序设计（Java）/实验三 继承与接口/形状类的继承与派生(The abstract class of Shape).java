class Rectangle extends Shape {
    double length, weight;

    public Rectangle(double length, double weight) {
        this.length = length;
        this.weight = weight;
    }

    @Override
    public double calArea() {
        return length * weight;
    }
}


class Circle extends Shape {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calArea() {
        return 3.14 * radius * radius;
    }
}
