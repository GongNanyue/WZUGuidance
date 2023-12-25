import javax.swing.*;
import java.awt.event.*;

public class ButtonExample {
    public static void main(String[] args) {
        // 创建 JFrame 实例
        JFrame frame = new JFrame("Button Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);

        // 创建 JButton
        JButton button = new JButton("Please click me");

        // 添加 ActionListener 到 JButton
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 在控制台打印消息
                System.out.println("Clicked");
                // 在信息框中显示消息
                JOptionPane.showMessageDialog(null, "Clicked");
            }
        });

        // 将按钮添加到 JFrame
        frame.getContentPane().add(button);

        // 设置布局管理器
        frame.setLayout(null);
        button.setBounds(50, 50, 200, 50);

        // 显示窗口
        frame.setVisible(true);
    }
}

