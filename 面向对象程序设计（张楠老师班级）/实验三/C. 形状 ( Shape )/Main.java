import java.util.Scanner;

abstract class Shape {
    abstract double getVolumn();

    abstract double getArea();
}

//cylinder, sphere, cube and cuboid
class Cylinder extends Shape {
    double radius, height;

    Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    double getVolumn() {
        return radius * radius * 3.14 * height;
    }

    @Override
    double getArea() {
        return radius * 2 * 3.14 * height + radius * radius * 3.14 * 2;
    }
}

class Sphere extends Shape {
    double radius;

    Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    double getVolumn() {
        return radius * radius * radius * 3.14 * 4 / 3;
    }

    @Override
    double getArea() {
        return 4 * 3.14 * radius * radius;
    }
}

class Cube extends Shape {
    double length;

    Cube(double length) {
        this.length = length;
    }

    @Override
    double getVolumn() {
        return length * length * length;
    }

    @Override
    double getArea() {
        return length * length * 6;
    }
}

class Cuboid extends Shape {
    double length, width, height;

    Cuboid(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    @Override
    double getVolumn() {
        return length * width * height;
    }

    @Override
    double getArea() {
        return (length * width + length * height + width * height) * 2;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var n = input.nextInt();
        for (var i = 0; i < n; i += 1) {
            var cylinder = new Cylinder(input.nextDouble(), input.nextDouble());
            var sphere = new Sphere(input.nextDouble());
            var cube = new Cube(input.nextDouble());
            var cuboid = new Cuboid(input.nextDouble(), input.nextDouble(), input.nextDouble());
            System.out.printf("%.2f %.2f\n%.2f %.2f\n%.2f %.2f\n%.2f %.2f\n", cylinder.getArea(), cylinder.getVolumn(), sphere.getArea(), sphere.getVolumn(), cube.getArea(), cube.getVolumn(), cuboid.getArea(), cuboid.getVolumn());
        }
    }
}