import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WindmillFrame extends JFrame {
    private WindmillPanel windmillPanel;

    public WindmillFrame() {
        // 初始化风车面板和控制按钮
        windmillPanel = new WindmillPanel();
        JButton speedButton = new JButton("调整速度");
        JButton sizeButton = new JButton("调整大小");

        // 添加事件监听器来处理按钮动作
        speedButton.addActionListener(e -> windmillPanel.changeSpeed());
        sizeButton.addActionListener(e -> windmillPanel.changeSize());

        // 设置布局并添加组件
        this.setLayout(new BorderLayout());
        this.add(windmillPanel, BorderLayout.CENTER);
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(speedButton);
        buttonPanel.add(sizeButton);
        this.add(buttonPanel, BorderLayout.SOUTH);

        // 设置窗口属性
        this.setSize(400, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            WindmillFrame frame = new WindmillFrame();
            frame.setVisible(true);
        });
    }
}

class WindmillPanel extends JPanel implements ActionListener {
    private double angle = 0; // 旋转角度
    private int speed = 100; // 旋转速度
    private int size = 100; // 风车大小
    private Timer timer;

    public WindmillPanel() {
        timer = new Timer(speed, this);
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        // 绘制风车
        Graphics2D g2d = (Graphics2D) g;
        int xCenter = getWidth() / 2;
        int yCenter = getHeight() / 2;
        g2d.rotate(angle, xCenter, yCenter);
        int[] xPoints = {xCenter, xCenter + size, xCenter, xCenter - size};
        int[] yPoints = {yCenter - size, yCenter, yCenter + size, yCenter};
        g2d.fillPolygon(xPoints, yPoints, 4);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        angle += 0.01; // 更新旋转角度
        repaint();
    }

    public void changeSpeed() {
        // 更新速度，这里简单地切换两种速度
        if (speed == 100) {
            speed = 50; // 加速
        } else {
            speed = 300; // 减速
        }
        timer.setDelay(speed);
    }

    public void changeSize() {
        // 更新大小，这里简单地在两个大小之间切换
        size = size == 100 ? 150 : 100;
        repaint();
    }
}
