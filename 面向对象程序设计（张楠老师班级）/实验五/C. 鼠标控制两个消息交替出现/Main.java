import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main {
    private JFrame frame;
    private JLabel label;
    private boolean isFunTextDisplayed = true;

    public Main() {
        frame = new JFrame("");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);

        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        label = new JLabel("Java is fun");
        label.setFont(new Font("Arial", Font.PLAIN, 18));
        panel.add(label);

        frame.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                isFunTextDisplayed = !isFunTextDisplayed;
                if (isFunTextDisplayed) {
                    label.setText("Java is fun");
                } else {
                    label.setText("Java is powerful");
                }
            }
        });

        frame.add(panel);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Main();
            }
        });
    }
}
