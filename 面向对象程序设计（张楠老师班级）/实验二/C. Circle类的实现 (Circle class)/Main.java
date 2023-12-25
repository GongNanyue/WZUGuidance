import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        var x=sc.nextInt();
        var y=sc.nextInt();
        var radius = sc.nextInt();

        System.out.printf("Center=(%d,%d) and Radius=%d\n",x,y,radius);
        System.out.printf("Diameter=%d\n",radius*2);
        System.out.printf("Area=%.1f\n",radius*radius*3.14);
        System.out.printf("Perimeter=%.1f\n",radius*2*3.14);
    }
}