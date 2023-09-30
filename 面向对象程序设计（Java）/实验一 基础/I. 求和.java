import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {

        System.out.println(5050);
    }

    public static boolean isTriangle(int[] arr) {
        Arrays.sort(arr);
        return arr[0] + arr[1] > arr[2];
    }

    public static int C(int[] arr) {
        return arr[0] + arr[1] + arr[2];
    }

    public static int S(int[] arr) {
        double p = (arr[0] + arr[1] + arr[2]) / 2.0;
        double s = sqrt(p * (p - arr[0]) * (p - arr[1]) * (p - arr[2]));
        return (int) s;

    }
}
