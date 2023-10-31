import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GeometricObject[] arr = new GeometricObject[4];
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        arr[0] = new Rectangle(a, b);
        a = sc.nextDouble();
        b = sc.nextDouble();
        arr[1] = new Rectangle(a, b);
        double r = sc.nextDouble();
        arr[2] = new Circle(r);
        r = sc.nextDouble();
        arr[3] = new Circle(r);
        System.out.printf("%.2f",sumArea(arr));

    }

    public static double sumArea(GeometricObject[] a) {
        double sum = 0;
        for (GeometricObject o : a) {
            sum += o.getArea();
        }
        return sum;
    }
}


abstract class GeometricObject {
    public abstract double getArea();
}

class Rectangle extends GeometricObject {
    double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }
}

class Circle extends GeometricObject {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }


    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}
