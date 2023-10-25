import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Window win = new Window();
        


    }
}

class Window extends JFrame {
    JButton button;

    Listener listener;

    public Window(){
        init();
        setVisible(true);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(100,100,400,400);
        setTitle("Handle Event");
    }

    void init(){
        button = new JButton("Please click me");
        listener = new Listener(this);
        button.addActionListener(listener);
        add(button);
    }
}

class Listener implements ActionListener{
    Window window;

    public Listener(Window window) {
        this.window = window;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("Clicked");
    }
}
