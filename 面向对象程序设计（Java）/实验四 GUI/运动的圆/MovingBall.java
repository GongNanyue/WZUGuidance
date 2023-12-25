import javax.swing.*;
import java.awt.*;

public class MovingBall extends JPanel implements Runnable {
    // 球的初始位置
    private int x = 0;
    private int y = 100; // 球的纵坐标

    public MovingBall() {
        Thread thread = new Thread(this);
        thread.start();
    }

    // 画球的方法
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.RED);  // 设置球的颜色
        g.fillOval(x, y, 50, 50); // 画球（圆形）
    }

    public void run() {
        while (true) { // 使球不断运动
            if (x > getWidth()) {
                x = -50; // 当球移到最右边时,重新从左边进入
            }
            x += 5; // 球的横坐标每次增加5
            repaint(); // 重新画球

            try {
                Thread.sleep(50); // 线程休眠50毫秒
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Moving Ball");
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new MovingBall());
        frame.setVisible(true);
    }
}
