import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class DraggableMessage extends JFrame {
    private JLabel label;
    private Random random = new Random();

    public DraggableMessage() {
        // 设置窗口的基本属性
        setTitle("Draggable Message");
        setSize(400, 400);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 创建标签，并设置初始文本和位置
        label = new JLabel("拖动我！", SwingConstants.CENTER);
        label.setBounds(100, 100, 100, 50);
        add(label);

        // 设置鼠标监听器来拖动标签
        label.addMouseMotionListener(new MouseAdapter() {
            public void mouseDragged(MouseEvent e) {
                label.setLocation(label.getX() + e.getX() - label.getWidth() / 2, label.getY() + e.getY() - label.getHeight() / 2);
                changeColor(); // 随机改变颜色
            }
        });
    }

    // 随机改变标签的背景颜色
    private void changeColor() {
        float r = random.nextFloat();
        float g = random.nextFloat();
        float b = random.nextFloat();
        Color randomColor = new Color(r, g, b);
        label.setForeground(randomColor);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new DraggableMessage().setVisible(true);
        });
    }
}
