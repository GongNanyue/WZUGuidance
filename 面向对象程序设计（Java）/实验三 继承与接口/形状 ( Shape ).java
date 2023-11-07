
abstract class Shape {
    public abstract double getArea();

    public abstract double getVolume();
}

class Cylinder extends Shape {
    double r;
    double h;

    public Cylinder(double r, double h) {
        this.r = r;
        this.h = h;
    }

    @Override
    public double getArea() {
        return 2 * 3.14 * r * r + 2 * 3.14 * r * h;
    }

    @Override
    public double getVolume() {
        return 3.14 * r * r * h;
    }
}

class Ball extends Shape {
    double r;

    public Ball(double r) {
        this.r = r;
    }

    @Override
    public double getArea() {
        return 4.0 * 3.14 * r * r;
    }

    @Override
    public double getVolume() {
        return 4.0 / 3.0 * 3.14 * r * r * r;
    }
}

class Cuber extends Shape {
    double a;

    public Cuber(double a) {
        this.a = a;
    }

    @Override
    public double getArea() {
        return 6 * a * a;
    }

    @Override
    public double getVolume() {
        return a * a * a;
    }
}

class Cuboid extends Shape {
    double a, b, c;

    public Cuboid(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double getArea() {
        return 2 * (a * b + a * c + b * c);
    }

    @Override
    public double getVolume() {
        return a * b * c;
    }
}
