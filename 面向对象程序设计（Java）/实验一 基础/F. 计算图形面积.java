import java.util.Scanner;

import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int op = sc.nextInt();
        if(op == 1){
            int r = sc.nextInt();
            System.out.printf("%.2f",r * r * 3.14);
        }else if(op == 2){
            int a = sc.nextInt(),b = sc.nextInt();
            System.out.printf("%.2f",(double)a * b);
        }else if(op == 3){
            int a = sc.nextInt();
            System.out.printf("%.2f",(double)a * a);
        }else{
            System.out.println("Invalid Data!");
        }
    }


}
