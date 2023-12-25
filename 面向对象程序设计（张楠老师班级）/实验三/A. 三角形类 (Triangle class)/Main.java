import java.util.Scanner;

class GeometricObject {
    GeometricObject(double side1, double side2, double side3, String color, boolean filled) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
        this.color = color;
        this.filled = filled;
    }

    double side1, side2, side3;
    String color;
    boolean filled;

    public double getArea() {
        double p = (side1 + side2 + side3) / 2;
        return Math.sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    @Override
    public String toString() {
        return String.format("Triangle: side1=%.1f side2=%.1f side3=%.1f color=%s filled=%b\nArea=%.2f\nPerimeter=%.2f\n", side1, side2, side3, color, filled, getArea(), getPerimeter());
    }

}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var side1 = input.nextDouble();
        var side2 = input.nextDouble();
        var side3 = input.nextDouble();
        var color = input.next();
        var filled = input.nextBoolean();
        var triangle = new GeometricObject(side1, side2, side3, color, filled);
        System.out.print(triangle.toString());
    }
}