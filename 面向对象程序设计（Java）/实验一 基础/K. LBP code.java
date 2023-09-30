import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};


        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt(), y = sc.nextInt();
        int[][] a1 = new int[x + 2][y + 2];
        for (int i = 1; i <= x; ++i)
            for (int j = 1; j <= y; ++j)
                a1[i][j] = sc.nextInt();
        String[][] a2 = new String[x + 2][y + 2];
        for(int i = 1;i <= x;++i)
            for (int j = 1;j <= y;++j)
                a2[i][j] = "";

        for (int i = 1; i <= x; ++i)
            for (int j = 1; j <= y; ++j)
                for (int k = 0; k < 8; ++k)
                    if (a1[i][j] >= a1[i + dx[k]][j + dy[k]])
                        a2[i][j] = "1" + a2[i][j];
                    else
                        a2[i][j] = "0" + a2[i][j];
        int[][] a3 = new int[x + 2][y + 2];
        for (int i = 1; i <= x; ++i)
            for (int j = 1; j <= y; ++j) {
                a3[i][j] = Integer.parseInt(String.valueOf(a2[i][j]), 2);
            }
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j)
                System.out.printf("%4d", a3[i][j]);
            System.out.println("");
        }
    }

}
