import java.awt.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Frame frame = new Frame();
        FileDialog fileDialog = new FileDialog(frame, "选择文件", FileDialog.LOAD);
        fileDialog.setDirectory(System.getProperty("user.dir"));
        fileDialog.setVisible(true);
        String filePath = fileDialog.getDirectory() + fileDialog.getFile();
        if (filePath.equals("nullnull")) System.exit(0);
        File file = new File(filePath);
        try {
            Desktop desktop = Desktop.getDesktop();
            if (desktop.isSupported(Desktop.Action.OPEN)) {
                desktop.open(file);
            } else {
                System.out.println("系统不支持打开文件操作。");
            }
            System.exit(0);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

