import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var id = input.next();
        var name = input.next();
        var sex = input.next();
        var chinese = input.nextDouble();
        var math = input.nextDouble();
        var english = input.nextDouble();
        System.out.printf("%s %s %s %.2f %.2f %.2f %.2f %.2f\n",id,name,sex,chinese,math,english,(chinese+math+english)/3,chinese+math+english);
    }
}
