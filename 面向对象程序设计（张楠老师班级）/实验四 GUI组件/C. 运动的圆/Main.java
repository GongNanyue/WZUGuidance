import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class BallMovement extends JFrame {
    JPanel ballPanel;
    Timer timer;
    double xPosition;

    public BallMovement() {
        setTitle("Ball Movement");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ballPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.red);
                g.fillOval((int) xPosition, getHeight() / 2 - 10, 20, 20);
            }
        };

        xPosition = 0;

        timer = new Timer(10, e -> {
            xPosition += 0.5;
            if (xPosition >= ballPanel.getWidth() - 20) {
                xPosition = 0;
            }
            ballPanel.repaint();
        });

        add(ballPanel);

        setVisible(true);
        timer.start();
    }
}

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(BallMovement::new);
    }
}
