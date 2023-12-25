import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class ToggleLabel {
    public static void main(String[] args) {
        // 创建 JFrame 实例
        JFrame frame = new JFrame("Toggle Label Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);

        // 创建标签并设置初始文字
        JLabel label = new JLabel("Java is fun", SwingConstants.CENTER);

        // 添加鼠标点击事件监听器
        label.addMouseListener(new MouseAdapter() {
            private boolean isFun = true;

            public void mouseClicked(MouseEvent e) {
                // 切换文本
                if (isFun) {
                    label.setText("Java is powerful");
                } else {
                    label.setText("Java is fun");
                }
                isFun = !isFun; // 切换状态
            }
        });

        // 添加标签到窗口并设置窗口为可见
        frame.add(label);
        frame.setVisible(true);
    }
}
