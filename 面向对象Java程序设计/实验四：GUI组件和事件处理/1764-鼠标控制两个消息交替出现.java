import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("summer");
        frame.setBounds(500,500,800,500);
        frame.setVisible(true);
        frame.setLayout(new FlowLayout());

        JLabel label = new JLabel("Java is fun");
        frame.add(label);

        frame.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (label.getText().equals("Java is fun")) {
                    label.setText("Java is powerful");
                } else if (label.getText().equals("Java is powerful")) {
                    label.setText("Java is fun");
                }
            }
        });


    }
}
