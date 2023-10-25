import java.util.Scanner;

class Complex {
    double a, b;

    public Complex(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public Complex(double a) {
        this.a = a;
    }

    public Complex() {
        a = 0;
        b = 0;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public Complex add(Complex rhs) {
        return new Complex(a + rhs.a, b + rhs.b);
    }

    public Complex substract(Complex rhs) {
        return new Complex(a - rhs.a, b - rhs.b);
    }

    public Complex multiply(Complex rhs) {
        return new Complex(a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a);
    }

    public Complex divide(Complex rhs) {
        return new Complex((a * rhs.a + b * rhs.b) / (rhs.a * rhs.a + rhs.b * rhs.b),
                (b * rhs.a - a * rhs.b) / (rhs.a * rhs.a + rhs.b * rhs.b));
    }

    public double calAbs() {
        return Math.sqrt(a * a + b * b);
    }

    public String s1() {
        return String.format("Real:%.2f imaginary:%.2f Fabs:%.2f", a, b, calAbs());
    }

    public String s2() {
        if (b >= 0.01)
            return String.format("%.2f+%.2fi", a, b);
        else if (b <= -0.01)
            return String.format("%.2f-%.2fi", a, -b);
        else
            return String.format("%.2f", a);
    }
}

public class Main {
    public static void main(String[] args) {
        Complex a = new Complex();
        Complex b = new Complex();
        Scanner sc = new Scanner(System.in);
        a.a = sc.nextDouble();
        a.b = sc.nextDouble();
        b.a = sc.nextDouble();
        b.b = sc.nextDouble();
        System.out.println(a.s1());
        System.out.println(b.s1());
        Complex x1 = a.add(b);
        Complex x2 = a.substract(b);
        Complex x3 = a.multiply(b);
        Complex x4 = a.divide(b);
        System.out.println(x1.s2());
        System.out.println(x2.s2());
        System.out.println(x3.s2());
        System.out.println(x4.s2());
    }
}
