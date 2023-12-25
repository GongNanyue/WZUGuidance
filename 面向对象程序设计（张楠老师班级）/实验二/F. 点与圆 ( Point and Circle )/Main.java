import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var n = input.nextInt();
        System.out.println("x=0.00,y=0.00");
        System.out.println("radius=0.00");
        for (var i =0;i<n;i+=1){
            var x = input.nextDouble();
            var y=input.nextDouble();
            var r = input.nextDouble();
            System.out.printf("x=%.2f,y=%.2f\nradius=%.2f\n",x,y,r);
        }
    }
}
