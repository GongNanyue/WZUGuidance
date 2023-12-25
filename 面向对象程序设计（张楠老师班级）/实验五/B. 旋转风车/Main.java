import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame {
    private WindmillPanel windmillPanel;
    private JButton speedButton;
    private JButton sizeButton;

    public Main() {
        super("Windmill App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        windmillPanel = new WindmillPanel();

        speedButton = new JButton("调整速度");
        sizeButton = new JButton("调整大小");

        speedButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                windmillPanel.adjustSpeed();
            }
        });

        sizeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                windmillPanel.adjustSize();
            }
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(speedButton);
        buttonPanel.add(sizeButton);

        add(windmillPanel, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Main();
            }
        });
    }
}

class WindmillPanel extends JPanel {
    private int angle = 0;  // 风车旋转角度
    private int speed = 10; // 风车旋转速度
    private int size = 100; // 风车大小

    public WindmillPanel() {
        setPreferredSize(new Dimension(400, 400));
        setBackground(Color.WHITE);

        // 创建定时器，用于控制风车旋转
        Timer timer = new Timer(100, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                angle = (angle + speed) % 360; // 更新旋转角度
                repaint(); // 重绘面板
            }
        });
        timer.start();
    }

    public void adjustSpeed() {
        speed += 10;
    }

    public void adjustSize() {
        size += 20;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        int centerX = getWidth() / 2;
        int centerY = getHeight() / 2;

        Graphics2D g2d = (Graphics2D) g.create();
        g2d.rotate(Math.toRadians(angle), centerX, centerY);

        g2d.setColor(Color.RED);
        g2d.fillArc(centerX - size / 2, centerY - size / 2, size, size, 0, 60);
        g2d.setColor(Color.BLUE);
        g2d.fillArc(centerX - size / 2, centerY - size / 2, size, size, 90, 60);
        g2d.setColor(Color.GREEN);
        g2d.fillArc(centerX - size / 2, centerY - size / 2, size, size, 180, 60);
        g2d.setColor(Color.YELLOW);
        g2d.fillArc(centerX - size / 2, centerY - size / 2, size, size, 270, 60);

        g2d.dispose();
    }
}
