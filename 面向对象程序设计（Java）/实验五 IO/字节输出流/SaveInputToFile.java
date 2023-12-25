import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class SaveInputToFile {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // 创建Scanner对象接收键盘输入
        System.out.println("Enter text (Type 'exit' to finish):");

        // 使用StringBuilder来收集输入的行
        StringBuilder sb = new StringBuilder();

        // 循环读取输入直到用户输入"exit"
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if ("exit".equalsIgnoreCase(line)) {
                break;
            }
            sb.append(line).append("\n"); // 添加新行符以保持文本格式
        }
        scanner.close(); // 关闭Scanner

        // 将StringBuilder内容转换为字节数组
        byte[] bytes = sb.toString().getBytes();

        // 使用FileOutputStream写入文件
        try (FileOutputStream fos = new FileOutputStream("d:\\ss.txt")) {
            fos.write(bytes);
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Text has been written to d:\\ss.txt");
    }
}
