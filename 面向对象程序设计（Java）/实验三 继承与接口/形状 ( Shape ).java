import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            double r = sc.nextDouble();
            double h = sc.nextDouble();
            Cylinder cylinder = new Cylinder(r, h);
            System.out.printf("%.2f %.2f\n", cylinder.getArea(), cylinder.getVolume());

            r = sc.nextDouble();
            Ball ball = new Ball(r);
            System.out.printf("%.2f %.2f\n", ball.getArea(), ball.getVolume());

            double a = sc.nextDouble();
            Cuber cuber = new Cuber(a);
            System.out.printf("%.2f %.2f\n", cuber.getArea(), cuber.getVolume());

            a = sc.nextDouble();
            double b = sc.nextDouble();
            double c = sc.nextDouble();
            Cuboid cuboid = new Cuboid(a,b,c);
            System.out.printf("%.2f %.2f\n", cuboid.getArea(), cuboid.getVolume());


        }

    }
}

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
