import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var a = input.nextDouble();
        var b = input.next();
        var c = input.next();
        var d = input.next();
        var e = input.nextDouble();
        System.out.printf("Loan: %.2f\nDate: %s\n%s\nFrame: %s\nCircle: %.2f\n",a,b,c,d,e);
    }
}