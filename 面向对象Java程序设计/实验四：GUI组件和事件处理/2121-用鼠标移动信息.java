import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Window win = new Window();


    }
}

class Window extends JFrame {
    JLabel label;
    Listener listener;

    public Window() {
        init();
        setVisible(true);
        setBounds(100, 100, 400, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setTitle("MoveMessage");
        setLayout(new FlowLayout());
    }

    void init() {
        label = new JLabel("Welcome to Java");
        listener = new Listener(this);
        label.addMouseListener(listener);
        add(label);
    }
}

class Listener implements MouseListener {

    Window window;

    public Listener(Window window) {
        this.window = window;
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        window.label.setLocation(e.getX(), e.getY());
    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}
