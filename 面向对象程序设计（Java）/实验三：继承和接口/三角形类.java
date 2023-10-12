import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        String color = sc.next();
        boolean filled = sc.nextBoolean();
        Triangle triangle = new Triangle(color,filled,a,b,c);
        System.out.print(triangle);

    }
}

class GeometricObject {
    String color;
    boolean filled;

    public GeometricObject(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }
}

class Triangle extends GeometricObject {
    double side1, side2, side3;

    public Triangle(String color, boolean filled) {
        super(color, filled);
        side1 = 1.0;
        side2 = 1.0;
        side3 = 1.0;
    }

    public Triangle(String color, boolean filled, double side1, double side2, double side3) {
        super(color, filled);
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double getArea() {
        double p = (side1 + side2 + side3) / 2;
        return Math.sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    public String toString() {
        return String.format("Triangle: side1=%.1f side2=%.1f side3=%.1f color=%s filled=%s\n" +
                        "Area=%.2f\n" +
                        "Perimeter=%.2f\n",
                side1, side2, side3, color, filled, getArea(), getPerimeter());
    }
}
