// 点与圆 ( Point and Circle )

import java.util.Scanner;

class Point {
    double x, y;

    Point() {
        x = 0;
        y = 0;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

class Circle {
    Point O;
    double r;

    Circle() {
        O = new Point();
        r = 0;
    }

    public Circle(Point o, double r) {
        O = o;
        this.r = r;
    }

    public void show() {
        System.out.printf("x=%.2f,y=%.2f\nradius=%.2f\n", O.x, O.y, r);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Circle c = new Circle();
        c.show();
        for (int i = 0; i < n; i++) {
            c.O.x = sc.nextDouble();
            c.O.y = sc.nextDouble();
            c.r = sc.nextDouble();
            c.show();
        }
    }
}