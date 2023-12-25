import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.nio.file.Files;

public class FileCopyApp {
    public static void main(String[] args) {
        // 创建窗口
        JFrame frame = new JFrame("File Copy Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);

        // 显示图片
        BufferedImage image = null;
        try {
            image = ImageIO.read(new File("c:\\a.jpg"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        JLabel picLabel = new JLabel(new ImageIcon(image));
        frame.add(picLabel, BorderLayout.CENTER);

        // 选择路径
        JTextField pathField = new JTextField("d:\\");
        frame.add(pathField, BorderLayout.NORTH);

        // 复制按钮
        JButton copyButton = new JButton("Copy");
        frame.add(copyButton, BorderLayout.SOUTH);
        copyButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                File sourceFile = new File("c:\\a.jpg");
                File destFile = new File(pathField.getText());
                try {
                    Files.copy(sourceFile.toPath(), destFile.toPath());
                    JOptionPane.showMessageDialog(frame, "File Copied Successfully!");
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        });

        // 显示窗口
        frame.setVisible(true);
    }
}
