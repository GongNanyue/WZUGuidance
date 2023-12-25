import java.util.Scanner;

abstract class GeometricObject {
    abstract double computeArea();
}

class Rectangle extends GeometricObject {
    Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    double width, height;

    @Override
    double computeArea() {
        return width * height;
    }
}

class Circle extends GeometricObject {
    Circle(double radius) {
        this.radius = radius;
    }

    double radius;

    @Override
    double computeArea() {
        return radius * radius * Math.PI;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var r1 = new Rectangle(input.nextDouble(), input.nextDouble());
        var r2 = new Rectangle(input.nextDouble(), input.nextDouble());
        var c1 = new Circle(input.nextDouble());
        var c2 = new Circle(input.nextDouble());
        System.out.printf("%.2f\n", r1.computeArea() + r2.computeArea() + c1.computeArea() + c2.computeArea());
    }
}
