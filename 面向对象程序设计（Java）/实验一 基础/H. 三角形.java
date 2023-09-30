import java.util.Arrays;
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            int[] arr = new int[3];
            arr[0] = sc.nextInt();
            arr[1] = sc.nextInt();
            arr[2] = sc.nextInt();
            if (isTriangle(arr)) {
                System.out.printf("%d %.0f\n", C(arr), S(arr));
            } else {
                System.out.println("Not a triangle.");
            }

        }
    }

    public static boolean isTriangle(int[] arr) {
        Arrays.sort(arr);
        return arr[0] + arr[1] > arr[2];
    }

    public static int C(int[] arr) {
        return arr[0] + arr[1] + arr[2];
    }

    public static double S(int[] arr) {
        double p = (arr[0] + arr[1] + arr[2]) / 2.0;
        return sqrt(p * (p - arr[0]) * (p - arr[1]) * (p - arr[2]));

    }
}
