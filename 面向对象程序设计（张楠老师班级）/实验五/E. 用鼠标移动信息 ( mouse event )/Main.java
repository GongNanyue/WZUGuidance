import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Main extends JPanel {

    private String message;
    private int messageX;
    private int messageY;
    private Color[] colors = {Color.RED, Color.GREEN, Color.BLUE, Color.YELLOW, Color.MAGENTA};
    private int colorIndex;

    public Main() {
        message = "Hello, World!";
        messageX = 100;
        messageY = 100;
        colorIndex = 0;

        // 添加鼠标监听器，以便拖动消息
        addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                messageX = e.getX();
                messageY = e.getY();
                repaint();
            }
        });

        addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                messageX = e.getX();
                messageY = e.getY();
                repaint();
            }
        });

        // 创建一个定时器，用于控制消息颜色的闪烁效果
        Timer timer = new Timer(500, e -> {
            colorIndex = (colorIndex + 1) % colors.length;
            repaint();
        });
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(colors[colorIndex]);
        g.drawString(message, messageX, messageY);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Message Panel");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            Main messagePanel = new Main();
            frame.add(messagePanel);
            frame.setSize(400, 300);
            frame.setVisible(true);
        });
    }
}