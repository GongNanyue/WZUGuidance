import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        var r1 = input.nextDouble();
        var i1 = input.nextDouble();
        var r2 = input.nextDouble();
        var i2 = input.nextDouble();
        System.out.printf("Real:%.2f imaginary:%.2f Fabs:%.2f\n",r1,i1,Math.sqrt(r1*r1+i1*i1));
        System.out.printf("Real:%.2f imaginary:%.2f Fabs:%.2f\n",r2,i2,Math.sqrt(r2*r2+i2*i2));
        var r3 = r1+r2;
        var i3 = i1+i2;
        if (r3>=0&&r3<0.01){
            if (i3>=0&&i3<0.01) System.out.println("0.00");
            else System.out.printf("%+.2fi\n",i3);
        }
        else {
            if (i3>=0&&i3<0.01) System.out.printf("%.2f\n",r3);
            else System.out.printf("%.2f%+.2fi\n",r3,i3);
        }
        r3 = r1-r2;
        i3=i1-i2;
        if (r3>=0&&r3<0.01){
            if (i3>=0&&i3<0.01) System.out.println("0.00");
            else System.out.printf("%+.2fi\n",i3);
        }
        else {
            if (i3>=0&&i3<0.01) System.out.printf("%.2f\n",r3);
            else System.out.printf("%.2f%+.2fi\n",r3,i3);
        }
        r3 = (r1*r2-i1*i2);
        i3 = (r1*i2+i1*r2);
        if (r3>=0&&r3<0.01){
            if (i3>=0&&i3<0.01) System.out.println("0.00");
            else System.out.printf("%+.2fi\n",i3);
        }
        else {
            if (i3>=0&&i3<0.01) System.out.printf("%.2f\n",r3);
            else System.out.printf("%.2f%+.2fi\n",r3,i3);
        }
        r3 = (r1*r2+i1*i2)/(r2*r2+i2*i2);
        i3 = (i1*r2-r1*i2)/(r2*r2+i2*i2);
        if (r3>=0&&r3<0.01){
            if (i3>=0&&i3<0.01) System.out.println("0.00");
            else System.out.printf("%+.2fi\n",i3);
        }
        else {
            if (i3>=0&&i3<0.01) System.out.printf("%.2f\n",r3);
            else System.out.printf("%.2f%+.2fi\n",r3,i3);
        }
    }
}