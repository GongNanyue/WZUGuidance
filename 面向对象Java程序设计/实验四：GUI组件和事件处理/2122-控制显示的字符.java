import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Window win = new Window(s);

    }
}

class Window extends JFrame {
    JLabel text;

    Listener listener;

    Window(String s) {
        init(s);
        setBounds(100, 100, 400, 400);
        setTitle("KeyEventDemo");
        setLayout(new FlowLayout());
        setVisible(true);
    }

    void init(String s) {
        text = new JLabel(s);
        add(text);
        listener = new Listener(this);
        this.addKeyListener(listener);
    }
}


class Listener implements KeyListener {
    Window win;

    public Listener(Window win) {
        this.win = win;
    }

    @Override
    public void keyTyped(KeyEvent e) {
        Point location = win.text.getLocation();
        if (e.getKeyChar() == KeyEvent.VK_DOWN || e.getKeyChar() == KeyEvent.VK_KP_DOWN) {
            win.text.setLocation(location.x - 1, location.y);
        } else if (e.getKeyChar() == KeyEvent.VK_UP || e.getKeyChar() == KeyEvent.VK_KP_UP) {
            win.text.setLocation(location.x + 1, location.y);
        } else if (e.getKeyChar() == KeyEvent.VK_LEFT || e.getKeyChar() == KeyEvent.VK_KP_LEFT) {
            win.text.setLocation(location.x, location.y - 1);
        } else if (e.getKeyChar() == KeyEvent.VK_RIGHT || e.getKeyChar() == KeyEvent.VK_KP_RIGHT) {
            win.text.setLocation(location.x, location.y + 1);
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
