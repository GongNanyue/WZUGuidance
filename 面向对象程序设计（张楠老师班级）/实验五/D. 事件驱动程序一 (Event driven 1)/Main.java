import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main {
    private JFrame frame;

    public Main() {
        frame = new JFrame("Handle Event");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(null);
        var button = new JButton("Please click me");
        button.setBounds(75, 50, 150, 50);
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                var dialog = new JDialog();
                dialog.setBounds(75, 50, 150, 50);
                var text = new JLabel("Clicked");
                dialog.add(text);
                dialog.setVisible(true);
            }
        });
        frame.add(button);
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
