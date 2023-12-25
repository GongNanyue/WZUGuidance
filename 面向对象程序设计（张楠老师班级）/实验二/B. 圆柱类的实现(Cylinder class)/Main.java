import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        var radius = sc.nextDouble();
        var height = sc.nextDouble();
        System.out.printf("%.2f\n",3.14*radius*radius*height);
    }
}

