import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();
        Circle circle = new Circle(r);
        System.out.printf("%.2f\n", circle.calArea());
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        Rectangle rectangle= new Rectangle(a,b);
        System.out.printf("%.2f\n", rectangle.calArea());
    }
}


abstract class Shape {
    public abstract double calArea();
}

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
