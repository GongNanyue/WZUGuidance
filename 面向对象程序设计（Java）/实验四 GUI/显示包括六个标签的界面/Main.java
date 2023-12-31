import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        Win win = new Win();
    }
}


class Win extends JFrame {
    JLabel black;
    JLabel blue;
    JLabel cyan;
    JLabel green;
    JLabel magenta;
    JLabel orange;

    Win() {
        black = new JLabel("Black");
        blue = new JLabel("Blue");
        cyan = new JLabel("Cyan");
        green = new JLabel("Green");
        magenta = new JLabel("Magenta");
        orange = new JLabel("Orange");

        black.setFont(new Font("Times Roman", Font.BOLD, 20));
        black.setForeground(Color.BLACK);
        black.setBorder(BorderFactory.createLineBorder(Color.YELLOW, 2));
        black.setOpaque(true);
        black.setBackground(Color.WHITE);


        blue.setFont(new Font("Times Roman", Font.BOLD, 20));
        blue.setForeground(Color.BLUE);
        blue.setBorder(BorderFactory.createLineBorder(Color.YELLOW, 2));
        blue.setOpaque(true);
        blue.setBackground(Color.WHITE);

        cyan.setFont(new Font("Times Roman", Font.BOLD, 20));
        cyan.setForeground(Color.CYAN);
        cyan.setBorder(BorderFactory.createLineBorder(Color.YELLOW, 2));
        cyan.setOpaque(true);
        cyan.setBackground(Color.WHITE);

        green.setFont(new Font("Times Roman", Font.BOLD, 20));
        green.setForeground(Color.GREEN);
        green.setBorder(BorderFactory.createLineBorder(Color.YELLOW, 2));
        green.setOpaque(true);
        green.setBackground(Color.WHITE);

        magenta.setFont(new Font("Times Roman", Font.BOLD, 20));
        magenta.setForeground(Color.MAGENTA);
        magenta.setBorder(BorderFactory.createLineBorder(Color.YELLOW, 2));
        magenta.setOpaque(true);
        magenta.setBackground(Color.WHITE);

        orange.setFont(new Font("Times Roman", Font.BOLD, 20));
        orange.setForeground(Color.ORANGE);
        orange.setBorder(BorderFactory.createLineBorder(Color.YELLOW, 2));
        orange.setOpaque(true);
        orange.setBackground(Color.WHITE);

        add(black);
        add(blue);
        add(cyan);
        add(green);
        add(magenta);
        add(orange);

        setLayout(new FlowLayout());
        setSize(500, 500);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("LabelDemo");
    }
}