import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = n / 100,b = n / 10 % 10,c = n % 10;
        if(a * a * a + b*b * b + c*c * c == n)
            System.out.println("Yes");
        else System.out.println("No");
    }
}
