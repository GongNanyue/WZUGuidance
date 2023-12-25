import java.util.Scanner;
import java.util.Vector;

interface Comparable {
    double getArea();
}


abstract class GeometricObject implements Comparable {
    String name;

    public static Comparable max(Comparable o1, Comparable o2) {
        return (o1.getArea() > o2.getArea()) ? o1 : o2;
    }
}

class Circle extends GeometricObject {
    double radius;

    Circle(String name, double radius) {
        this.name = name;
        this.radius = radius;
    }

    public double getArea() {
        return radius * radius * Math.PI;
    }

}

class Rectangle extends GeometricObject {
    double length, width;

    Rectangle(String name, double length, double width) {
        this.name = name;
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }
}


public class Main {
    public static void main(String args[]) {
        var in = new Scanner(System.in);
        var r1 = new Rectangle(in.next(), in.nextDouble(), in.nextDouble());
        var r2 = new Rectangle(in.next(), in.nextDouble(), in.nextDouble());
        var c1 = new Circle(in.next(), in.nextDouble());
        var c2 = new Circle(in.next(), in.nextDouble());
        var r = Rectangle.class.cast(GeometricObject.max(r1, r2));
        var c = Circle.class.cast(GeometricObject.max(c1, c2));
        System.out.printf("%s %.2f %.2f %.2f\n", r.name, r.length, r.width, r.getArea());
        System.out.printf("%s %.2f %.2f\n", c.name, c.radius, c.getArea());
    }
}
