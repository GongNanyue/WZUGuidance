import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt(),h = sc.nextInt();;
        Cylinder cylinder = new Cylinder(r,h);
        System.out.printf("%.2f",cylinder.getVolume());
    }
}

class Cylinder{
    static final double Pi = 3.14;
    private int radius;
    private int height;

    public Cylinder(int radius, int height) {
        this.radius = radius;
        this.height = height;
    }

    double getVolume(){
        return Pi * radius * radius * height;
    }
}
