import java.io.FileInputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try (FileInputStream in = new FileInputStream("D:\\text.txt")) {
            byte[] buffer = new byte[1024];
            int length = in.read(buffer);
            while (length != -1) {
                System.out.print(new String(buffer, 0, length));
                length = in.read(buffer);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}