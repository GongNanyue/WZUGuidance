import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WindmillPanel extends JPanel implements ActionListener {
    private static final int TIMER_DELAY = 100; // 更新间隔时间（毫秒）
    private int angle = 0; // 风车旋转的当前角度

    public WindmillPanel() {
        // 设置计时器，用于风车的旋转
        new Timer(TIMER_DELAY, this).start();
    }

    // 绘制组件的外观
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        // 计算扇叶的大小和位置
        int xCenter = getWidth() / 2;
        int yCenter = getHeight() / 2;
        int radius = Math.min(xCenter, yCenter) * 3 / 4; // 扇叶的半径

        // 设置扇叶颜色为红色
        g.setColor(Color.RED);

        // 绘制四个扇叶
        for (int i = 0; i < 4; i++) {
            // 绘制扇形
            g.fillArc(xCenter - radius, yCenter - radius, radius * 2, radius * 2, angle + i * 90, 45);
        }

        // 设置边框颜色
        g.setColor(Color.BLACK);
        // 绘制外圈边框
        g.drawOval(xCenter - radius - 6, yCenter - radius - 6, radius * 2 + 3, radius * 2 + 3);
    }

    // 处理计时器事件
    @Override
    public void actionPerformed(ActionEvent e) {
        // 更新角度
        angle = (angle + 10) % 360;
        // 重新绘制面板
        repaint();
    }

    // 创建窗口并显示风车面板
    public static void createAndShowGUI() {
        JFrame frame = new JFrame("My JFrame");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new WindmillPanel());
        frame.setSize(400, 400);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        // 在事件分发线程中运行界面创建
        SwingUtilities.invokeLater(WindmillPanel::createAndShowGUI);
    }
}
