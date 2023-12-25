import java.util.Scanner;

class Block {

    int value = 0;
    int[][] cmpValue = new int[3][3];
    int LBP = 0;
}

public class Main {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        var row = scanner.nextInt();
        var col = scanner.nextInt();
        row += 2;
        col += 2;
        var blocks = new Block[row][col];
        for (int i = 0; i < row; i += 1)
            for (int j = 0; j < col; j += 1) blocks[i][j] = new Block();
        for (int i = 1; i < row - 1; i += 1)
            for (int j = 1; j < col - 1; j += 1) blocks[i][j].value = scanner.nextInt();
        for (int i = 1; i < row - 1; i += 1)
            for (int j = 1; j < col - 1; j += 1) {
                for (int _i = -1; _i <= 1; _i += 1)
                    for (int _j = -1; _j <= 1; _j += 1) {
                        if (blocks[i + _i][j + _j].value <= blocks[i][j].value)
                            blocks[i][j].cmpValue[1 + _i][1 + _j] = 1;
                        else blocks[i][j].cmpValue[1 + _i][1 + _j] = 0;
                    }

                blocks[i][j].LBP |= blocks[i][j].cmpValue[0][0] << 0;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[0][1] << 1;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[0][2] << 2;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[1][2] << 3;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[2][2] << 4;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[2][1] << 5;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[2][0] << 6;
                blocks[i][j].LBP |= blocks[i][j].cmpValue[1][0] << 7;
            }
        for (int i = 1; i < row - 1; i += 1) {
            for (int j = 1; j < col - 1; j += 1) System.out.printf("%4d", blocks[i][j].LBP);
            System.out.print('\n');
        }
    }
}
