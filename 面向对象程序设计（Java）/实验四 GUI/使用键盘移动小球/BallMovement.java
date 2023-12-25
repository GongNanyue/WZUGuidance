import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BallMovement extends JFrame {
    private BallPanel ballPanel = new BallPanel();

    public BallMovement() {
        // 将面板添加到窗口
        add(ballPanel);
        // 设置窗口属性
        setResizable(false);
        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);  // Center the frame
        setVisible(true);

        // 添加键盘监听器到面板
        ballPanel.setFocusable(true);
    }

    // 面板类，绘制小球并响应键盘事件
    private class BallPanel extends JPanel implements KeyListener {
        private int x = 100; // 小球的起始x坐标
        private int y = 100; // 小球的起始y坐标
        private int radius = 15; // 小球的半径

        public BallPanel() {
            // 添加键盘监听器
            addKeyListener(this);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.fillOval(x - radius, y - radius, 2 * radius, 2 * radius); // 绘制小球
        }

        // 键盘事件处理
        public void keyPressed(KeyEvent e) {
            switch (e.getKeyCode()) {
                case KeyEvent.VK_UP:    y -= 10; break; // 向上移动
                case KeyEvent.VK_DOWN:  y += 10; break; // 向下移动
                case KeyEvent.VK_LEFT:  x -= 10; break; // 向左移动
                case KeyEvent.VK_RIGHT: x += 10; break; // 向右移动
            }
            repaint();  // 重新绘制小球在新位置
        }

        public void keyReleased(KeyEvent e) { }
        public void keyTyped(KeyEvent e) { }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(300, 300); // 设置面板大小
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new BallMovement();
            }
        });
    }
}
