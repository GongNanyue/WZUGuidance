import org.intellij.lang.annotations.JdkConstants;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.util.*;
import javax.swing.*;
import javax.swing.border.Border;

class Tag extends JPanel {
    Tag(JLabel label,Color color) {
        this.setPreferredSize(new Dimension(120,50));
        this.setLayout(new BorderLayout());
        label.setHorizontalAlignment(SwingConstants.CENTER);
        label.setFont(new Font("Times Roman",Font.BOLD,20));
        label.setForeground(color);
        this.add(label,BorderLayout.CENTER);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.white);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(Color.yellow);
        g2d.setStroke(new BasicStroke(5));
        g2d.drawRect(0, 0, this.getWidth(), this.getHeight());
    }

}

public class Main {
    static JFrame rootFrame = new JFrame();

    public static void main(String args[]) {
        rootFrame.setVisible(true);
        rootFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        rootFrame.setSize(800, 600);
        rootFrame.setLayout(new FlowLayout());
        var blackTag = new Tag(new JLabel("black"),Color.black);
        var blueTag = new Tag(new JLabel("blue"),Color.blue);
        var cyanTag = new Tag(new JLabel("cyan"),Color.cyan);
        var greenTag = new Tag(new JLabel("green"),Color.green);
        var magentaTag = new Tag(new JLabel("magenta"),Color.magenta);
        var orangeTag = new Tag(new JLabel("orange"),Color.orange);
        rootFrame.add(blackTag);
        rootFrame.add(blueTag);
        rootFrame.add(cyanTag);
        rootFrame.add(greenTag);
        rootFrame.add(magentaTag);
        rootFrame.add(orangeTag);
    }
}

