import java.util.Scanner;
import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        for (int i = 1; i <= 9; ++i)
            for (int j = 1; j <= 9; ++j)
                if (i != j) {
                    int n = i * 1100 + j * 11;
                    if(isSq(n)){
                        System.out.println(n);
                    }

                }
    }

    public static boolean isSq(int n) {
        int s = (int) sqrt(n);
        return s * s == n;
    }
}
