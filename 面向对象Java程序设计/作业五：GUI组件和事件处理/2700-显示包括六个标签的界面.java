import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.*;


public class Main {
    public static void main(String[] args) throws InterruptedException {
        JFrame frame = new JFrame("LabelDemo");
        frame.setVisible(true);
        frame.setBounds(500, 500, 800, 500);
        frame.setLayout(new FlowLayout());

        JLabel black = new JLabel("black");
        black.setFont(new Font("Times Roman", Font.BOLD, 20));
        black.setBackground(Color.white);
        black.setForeground(Color.BLACK);
        black.setBorder(new LineBorder(Color.YELLOW));
        frame.add(black);

        JLabel blue = new JLabel("blue");
        blue.setFont(new Font("Times Roman", Font.BOLD, 20));
        blue.setBackground(Color.white);
        blue.setForeground(Color.BLUE);
        blue.setBorder(new LineBorder(Color.YELLOW));
        frame.add(blue);


        JLabel cyan = new JLabel("cyan");
        cyan.setFont(new Font("Times Roman", Font.BOLD, 20));
        cyan.setBackground(Color.white);
        cyan.setForeground(Color.CYAN);
        cyan.setBorder(new LineBorder(Color.YELLOW));
        frame.add(black);


        JLabel green = new JLabel("green");
        green.setFont(new Font("Times Roman", Font.BOLD, 20));
        green.setBackground(Color.white);
        green.setForeground(Color.GREEN);
        green.setBorder(new LineBorder(Color.YELLOW));
        frame.add(green);


        JLabel magenta = new JLabel("magenta");
        magenta.setFont(new Font("Times Roman", Font.BOLD, 20));
        magenta.setBackground(Color.white);
        magenta.setForeground(Color.magenta);
        magenta.setBorder(new LineBorder(Color.YELLOW));
        frame.add(magenta);

        JLabel orange = new JLabel("orange");
        orange.setFont(new Font("Times Roman", Font.BOLD, 20));
        orange.setBackground(Color.white);
        orange.setForeground(Color.ORANGE);
        orange.setBorder(new LineBorder(Color.YELLOW));
        frame.add(orange);


    }
}
