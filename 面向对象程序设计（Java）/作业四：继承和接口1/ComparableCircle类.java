import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double r1 = sc.nextDouble();
        double r2 = sc.nextDouble();
        ComparableCircle c1 = new ComparableCircle(r1);
        ComparableCircle c2 = new ComparableCircle(r2);
        if (c1.compareTo(c2) > 0) {
            System.out.printf("The max circle's area is %.2f\n", c1.getArea());
        } else {
            System.out.printf("The max circle's area is %.2f\n", c2.getArea());
        }
    }
}

class Circle {
    double r;

    public Circle(double r) {
        this.r = r;
    }

    public double getArea() {
        return Math.PI * r * r;
    }
}

class ComparableCircle extends Circle implements Comparable<Circle> {

    public ComparableCircle(double r) {
        super(r);
    }

    @Override
    public int compareTo(Circle o) {
        return Double.compare(this.r, o.r);
    }
}
