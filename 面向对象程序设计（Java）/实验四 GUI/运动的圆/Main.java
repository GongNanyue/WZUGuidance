import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.MalformedURLException;
import java.net.URL;

public class Main {
    public static void main(String[] args) {
        Window win = new Window();

    }
}

class Window extends JFrame {


    public Window() {
        setSize(400, 200);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        
        
        Ball ball = new Ball();
        add(ball);
        Thread thread = new Thread(ball);
        thread.start();
        
        
        setVisible(true);
    }
}

class Ball extends JPanel implements Runnable {
    public int x = 100;
    public int y = 50;
    public int width = 100;
    public int height = 100;

    @Override
    protected void paintComponent(Graphics g) {
        g.setColor(Color.yellow);
        g.fillOval(x, y, width, height);
    }


    @Override
    public void run() {
        while (true) {
            if (x > getWidth()) {
                x = -100;
            }
            x += 5;
            repaint();

            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
