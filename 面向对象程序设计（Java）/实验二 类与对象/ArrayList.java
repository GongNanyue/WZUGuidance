import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Loan loan = new Loan();
        Data data = new Data();
        String string = new String();
        Frame frame = new Frame();
        Circle circle = new Circle();
        loan.loan = sc.nextDouble();
        data.data = sc.next();
        string = sc.next();
        frame.name = sc.next();
        circle.radius = sc.nextDouble();
        System.out.println(loan);
        System.out.println(data);
        System.out.println(string);
        System.out.println(frame);
        System.out.println(circle);
    }
}

class Loan {
    double loan;

    public Loan() {
    }

    public Loan(double loan) {
        this.loan = loan;
    }

    @Override
    public String toString() {
        return String.format("Loan: %.2f", loan);
    }
}

class Data {
    String data;

    public Data() {
    }

    public Data(String data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return String.format("Date: %s", data);
    }
}

class Frame {
    String name;

    public Frame() {
    }

    public Frame(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return String.format("Frame: %s", name);
    }
}

class Circle {
    double radius;

    public Circle() {
    }

    Circle(double radius) {
        this.radius = radius;
    }

    public String toString() {
        return String.format("Circle: %.2f", radius);
    }
}
