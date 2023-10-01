import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            double edge = sc.nextDouble();
            Cube obj = new Cube(edge);
            obj.calArea();
            obj.calVolume();
            System.out.println("obj" + i + " " + obj);

        }
    }


}

class Cube {
    private double edge;
    private double volume;
    private double area;

    public Cube(double edge) {
        this.edge = edge;
    }

    void calVolume() {
        this.volume = edge * edge * edge;
    }

    void calArea() {
        this.area = 6 * edge * edge;
    }

    @Override
    public String toString() {
        return String.format("Volume:%.2f; Area:%.2f", this.volume, this.area);
    }

    void display() {
        System.out.println(this.toString());
    }
}
