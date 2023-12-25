import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;
import java.io.IOException;

public class Main extends JFrame {
    private JTextArea textArea;
    private JButton saveButton;

    public Main() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);
        setLocationRelativeTo(null);

        textArea = new JTextArea();
        saveButton = new JButton("保存");

        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                saveToFile();
            }
        });

        setLayout(new BorderLayout());
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        add(saveButton, BorderLayout.SOUTH);
    }

    private void saveToFile() {
        String content = textArea.getText();

        if (content.isEmpty()) {
            JOptionPane.showMessageDialog(this, "请输入要保存的内容。", "提示", JOptionPane.WARNING_MESSAGE);
            return;
        }

        // 将内容写入文件
        try (FileOutputStream fos = new FileOutputStream("ss.txt")) {
            fos.write(content.getBytes());
            JOptionPane.showMessageDialog(this, "内容已成功写入文件。", "提示", JOptionPane.INFORMATION_MESSAGE);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "写入文件时发生错误：" + e.getMessage(), "错误", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Main().setVisible(true);
            }
        });
    }
}
