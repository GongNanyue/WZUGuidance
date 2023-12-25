import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class BallMovement extends JFrame {
    JPanel ballPanel;
    int xPosition;
    int yPosition;

    public BallMovement() {
        setTitle("ControlSphere");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        xPosition = 200;
        yPosition = 150;
        ballPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.red);
                g.fillOval( xPosition, yPosition, 20, 20);
            }
        };
        ballPanel.setBounds(0,0,getWidth(),getHeight());



        var leftButton = new JButton("向左");
        var rightButton = new JButton("向右");
        var upButton = new JButton("向上");
        var downButton = new JButton("向下");
        leftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                xPosition-=1;
                ballPanel.repaint();
            }
        });
        rightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                xPosition+=1;
                ballPanel.repaint();
            }
        });
        upButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                yPosition-=1;
                ballPanel.repaint();
            }
        });
        downButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                yPosition+=1;
                ballPanel.repaint();
            }
        });
        leftButton.setBounds(300,50,80,40);
        rightButton.setBounds(300,100,80,40);
        upButton.setBounds(300,150,80,40);
        downButton.setBounds(300,200,80,40);
        add(leftButton);
        add(rightButton);
        add(upButton);
        add(downButton);
        add(ballPanel);
        setVisible(true);
    }
}

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(BallMovement::new);
    }
}
