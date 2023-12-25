import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            var n = sc.nextInt();
            for (var i=1;i<=n;i+=1){
                var edge = sc.nextDouble();
                System.out.printf("obj%d Volume:%.2f; Area:%.2f\n",i,edge*edge*edge,edge*edge*6);
        }
    }
}