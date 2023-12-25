import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.util.*;
import javax.swing.*;

public class Main {
    static JFrame rootFrame = new JFrame();

    public static void main(String args[]) {
        rootFrame.setVisible(true);
        rootFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        rootFrame.getContentPane().setBackground(Color.white);

        rootFrame.setSize(800, 600);
        rootFrame.setLayout(null);
        var button = new JButton("Change Button Text Color");
        button.setBounds(300, 285, 200, 30);
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                var colorDialog = new ColorDialog();
                colorDialog.setVisible(true);
            }
        });
        rootFrame.add(button);
    }
}

class ColorDialog extends JDialog {
    public ColorDialog() {
        super();
        this.setBounds(0, 400, 800, 200);
        redScrollBar.setMinimum(0);
        greenScrollBar.setMinimum(0);
        blueScrollBar.setMinimum(0);
        redScrollBar.setMaximum(255);
        greenScrollBar.setMaximum(255);
        blueScrollBar.setMaximum(255);
        redScrollBar.setValue(Main.rootFrame.getBackground().getRed());
        greenScrollBar.setValue(Main.rootFrame.getBackground().getGreen());
        blueScrollBar.setValue(Main.rootFrame.getBackground().getBlue());
        redScrollBar.addAdjustmentListener(new AdjustmentListener() {
            @Override
            public void adjustmentValueChanged(AdjustmentEvent e) {
                var preColor = Main.rootFrame.getBackground();
                var newColor = new Color(e.getValue(), preColor.getGreen(), preColor.getBlue());
                Main.rootFrame.getContentPane().setBackground(newColor);
            }
        });
        greenScrollBar.addAdjustmentListener(new AdjustmentListener() {
            @Override
            public void adjustmentValueChanged(AdjustmentEvent e) {
                var preColor = Main.rootFrame.getBackground();
                var newColor = new Color(preColor.getBlue(), e.getValue(), preColor.getBlue());
                Main.rootFrame.getContentPane().setBackground(newColor);
            }
        });
        blueScrollBar.addAdjustmentListener(new AdjustmentListener() {
            @Override
            public void adjustmentValueChanged(AdjustmentEvent e) {
                var preColor = Main.rootFrame.getBackground();
                var newColor = new Color(preColor.getRed(), preColor.getGreen(), e.getValue());
                Main.rootFrame.getContentPane().setBackground(newColor);
            }
        });
        var rootBox = new Box(BoxLayout.Y_AXIS);
        var redBox = new Box(BoxLayout.X_AXIS);
        var greenBox = new Box(BoxLayout.X_AXIS);
        var blueBox = new Box(BoxLayout.X_AXIS);
        var buttonsBox = new Box(BoxLayout.X_AXIS);
        redBox.add(new JLabel("Red"));
        redBox.add(redScrollBar);
        greenBox.add(new JLabel("Green"));
        greenBox.add(greenScrollBar);
        blueBox.add(new JLabel("Blue"));
        blueBox.add(blueScrollBar);
        buttonsBox.add(new JButton("OK"));
        buttonsBox.add(new JButton("Cancel"));
        rootBox.add(redBox);
        rootBox.add(greenBox);
        rootBox.add(blueBox);
        rootBox.add(buttonsBox);
        this.add(rootBox);
    }

    Scrollbar redScrollBar = new Scrollbar(JScrollBar.HORIZONTAL);
    Scrollbar greenScrollBar = new Scrollbar(JScrollBar.HORIZONTAL);
    Scrollbar blueScrollBar = new Scrollbar(JScrollBar.HORIZONTAL);
}
