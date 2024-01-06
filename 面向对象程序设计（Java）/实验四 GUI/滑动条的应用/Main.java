import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {
        new SliderWindow();
    }
}

class SliderDialog extends JDialog {
    JPanel panel;

    JSlider r, g, b;

    JButton confirm;

    SliderWindow win;

    public SliderDialog(SliderWindow win) {
        this.win = win;
        setTitle(getClass().getName());
        setBounds(100, 100, 300, 550);
        setLayout(null);
        init();
        setVisible(false);
    }

    void init() {
        panel = new JPanel();
        r = new JSlider(SwingConstants.HORIZONTAL, 0, 255, 0);
        g = new JSlider(SwingConstants.HORIZONTAL, 0, 255, 0);
        b = new JSlider(SwingConstants.HORIZONTAL, 0, 255, 0);

        confirm = new JButton("确定");

        panel.setBounds(0, 0, 300, 300);
        r.setBounds(0, 300, 300, 50);
        b.setBounds(0, 350, 300, 50);
        g.setBounds(0, 400, 300, 50);
        confirm.setBounds(0, 450, 300, 50);

        r.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                panel.setBackground(new Color(r.getValue(), g.getValue(), b.getValue()));
            }
        });

        b.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                panel.setBackground(new Color(r.getValue(), g.getValue(), b.getValue()));
            }
        });

        g.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                panel.setBackground(new Color(r.getValue(), g.getValue(), b.getValue()));
            }
        });

        confirm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                win.getContentPane().setBackground(new Color(r.getValue(), g.getValue(), b.getValue()));
                setVisible(false);
            }
        });

        this.add(panel);
        this.add(r);
        this.add(g);
        this.add(b);
        this.add(confirm);
    }
}

class SliderWindow extends JFrame {
    JButton change;
    SliderDialog dialog;

    public SliderWindow() {
        setTitle(this.getClass().getName());
        setBounds(500, 500, 500, 300);
        setLayout(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        init();
        setVisible(true);
    }

    void init() {
        change = new JButton("改变颜色");
        dialog = new SliderDialog(this);

        change.setBounds(0, 200, 500, 50);

        change.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.setVisible(true);
            }
        });
        this.add(change);
    }
}
