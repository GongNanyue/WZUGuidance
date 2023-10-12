import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int l,w,h;
        l = sc.nextInt();
        w = sc.nextInt();
        h = sc.nextInt();
        Cuboid cuboid = new Cuboid(l,w,h);
        System.out.println(cuboid.getBottomArea()       );
        System.out.println(cuboid.getVolume());
    }
}

class Cuboid {
    int length;
    int width;
    int height;

    public Cuboid(int length, int width, int height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public int getBottomArea(){
        return length * width;
    }

    public int getVolume(){
        return getBottomArea() * height;
    }
}