import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            int d1 = 0, d2 = 0, l = 0;
            String a = sc.next(), b = sc.next();
            int len = sc.nextInt();
            for (int i = 0; i < a.length(); ++i) {
                for (int j = 0; j < b.length(); ++j) {
                    int l1 = 0;
                    for (int k = 0; k < len && i + k < a.length() && j + k < b.length(); ++k) {
                        if (a.charAt(i + k) != b.charAt(j + k)) {
                            break;
                        } else {
                            l1++;
                        }
                    }
                    if (l1 > l) {
                        d1 = i;
                        d2 = j;
                        l = l1;
                    }
                }
            }
            for (int k = 0; d1 + k < a.length() && d2 + k < b.length(); ++k) {
                if (a.charAt(d1 + k) == b.charAt(d2 + k)) System.out.printf("%c", a.charAt(d1 + k));
                else break;
            }
            System.out.println();


    }
}
