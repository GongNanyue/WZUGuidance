import java.util.Scanner;
import java.util.Vector;

class Circle {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }
}

interface Comparable {
    double compareTo(ComparableCircle other);
}

class ComparableCircle extends Circle implements Comparable {
    ComparableCircle(double radius) {
        super(radius);
    }

    public double compareTo(ComparableCircle other) {
        return (this.radius > other.radius) ? this.radius * this.radius * Math.PI : other.radius * other.radius * Math.PI;
    }
}

public class Main {
    public static void main(String args[]) {
        var in  = new Scanner(System.in);
        var a = new ComparableCircle(in.nextDouble());
        var b = new ComparableCircle(in.nextDouble());
        System.out.printf("The max circle's area is %.2f\n",a.compareTo(b));
    }
}
