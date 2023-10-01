import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int r = sc.nextInt();
        Circle circle = new Circle(x,y,r);
        circle.output();
    }
}

class Circle {
    static final double PI = 3.14;
    private int radius;
    private int x;
    private int y;

    public Circle() {
        this.x = 0;
        this.y = 0;
        this.radius = 1;
    }
    public Circle(int x,int y,int r) {
        this.x = x;
        this.y = y;
        this.radius = r;
    }

    public int calDiameter() {
        return 2 * radius;
    }

    public double calArea() {
        return PI * radius * radius;
    }

    public double calPerimeter() {
        return 2 * PI * radius;
    }


    public void output() {
        System.out.printf("Center=(%d,%d) and Radius=%d\n" +
                "Diameter=%d\n" +
                "Area=%.1f\n" +
                "Perimeter=%.1f", x, y, radius, calDiameter(), calArea(), calPerimeter());
    }
}