import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

class TextMovement extends JFrame {
    JTextField textField;
    int xPosition;
    int yPosition;

    public TextMovement() {
        setTitle("Move me");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        xPosition = 100;
        yPosition = 100;
        textField = new JTextField();
        textField.setBounds(xPosition, yPosition, 200, 50);

        textField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
                if (keyCode == KeyEvent.VK_UP) {
                    yPosition -= 1;
                } else if (keyCode == KeyEvent.VK_DOWN) {
                    yPosition += 1;
                } else if (keyCode == KeyEvent.VK_LEFT) {
                    xPosition -= 1;
                } else if (keyCode == KeyEvent.VK_RIGHT) {
                    xPosition += 1;
                }
                textField.setBounds(xPosition, yPosition, 200, 50);
            }
        });

//        var leftButton = new JButton("向左");
//        var rightButton = new JButton("向右");
//        var upButton = new JButton("向上");
//        var downButton = new JButton("向下");
//        leftButton.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                xPosition -= 1;
//                textField.repaint();
//            }
//        });
//        rightButton.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                xPosition += 1;
//                textField.repaint();
//            }
//        });
//        upButton.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                yPosition -= 1;
//                textField.repaint();
//            }
//        });
//        downButton.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                yPosition += 1;
//                textField.repaint();
//            }
//        });
//        leftButton.setBounds(300, 50, 80, 40);
//        rightButton.setBounds(300, 100, 80, 40);
//        upButton.setBounds(300, 150, 80, 40);
//        downButton.setBounds(300, 200, 80, 40);
//        add(leftButton);
//        add(rightButton);
//        add(upButton);
//        add(downButton);
        add(textField);
        setVisible(true);
    }
}

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(TextMovement::new);
    }
}