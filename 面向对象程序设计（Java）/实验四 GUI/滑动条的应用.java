import javax.swing.*;
import javax.swing.event.ChangeListener;
import java.awt.*;

class ColorDialog extends JDialog {
    private final JSlider redSlider, greenSlider, blueSlider;
    private final JLabel colorPreview;
    private Color selectedColor;

    public ColorDialog(JFrame parent) {
        super(parent, "Select Color", true);
        setLayout(new GridLayout(0, 1));

        // 创建滑块
        redSlider = createColorSlider();
        greenSlider = createColorSlider();
        blueSlider = createColorSlider();

        // 添加滑块到对话框
        addComponentWithLabel("Red: ", redSlider);
        addComponentWithLabel("Green: ", greenSlider);
        addComponentWithLabel("Blue: ", blueSlider);

        // 颜色预览区域
        colorPreview = new JLabel();
        colorPreview.setOpaque(true);
        colorPreview.setPreferredSize(new Dimension(100, 100));
        add(colorPreview);

        // 注册滑块事件监听器
        ChangeListener colorChangeListener = e -> updateColorPreview();
        redSlider.addChangeListener(colorChangeListener);
        greenSlider.addChangeListener(colorChangeListener);
        blueSlider.addChangeListener(colorChangeListener);

        // 确定按钮，当用户完成颜色选择时，关闭对话框
        JButton okButton = new JButton("OK");
        okButton.addActionListener(e -> setVisible(false));
        add(okButton);

        pack();
        setLocationRelativeTo(parent);
    }

    // 创建颜色滑块
    private JSlider createColorSlider() {
        JSlider slider = new JSlider(0, 255, 0);
        slider.setMajorTickSpacing(50);
        slider.setMinorTickSpacing(10);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        return slider;
    }

    // 添加组件和标签
    private void addComponentWithLabel(String label, JComponent component) {
        JPanel panel = new JPanel(new BorderLayout());
        panel.add(new JLabel(label), BorderLayout.WEST);
        panel.add(component, BorderLayout.CENTER);
        add(panel);
    }

    // 更新颜色预览
    private void updateColorPreview() {
        selectedColor = new Color(redSlider.getValue(), greenSlider.getValue(), blueSlider.getValue());
        colorPreview.setBackground(selectedColor);
    }

    // 获取选择的颜色
    public Color getSelectedColor() {
        return selectedColor;
    }
}


// 主窗口
public class MainFrame extends JFrame {
    private final JButton changeColorButton;
    private final JPanel colorPanel;

    public MainFrame() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        colorPanel = new JPanel();
        colorPanel.setPreferredSize(new Dimension(200, 200));
        add(colorPanel, BorderLayout.CENTER);

        changeColorButton = new JButton("Change Color");
        changeColorButton.addActionListener(e -> showColorDialog());
        add(changeColorButton, BorderLayout.SOUTH);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void showColorDialog() {
        ColorDialog colorDialog = new ColorDialog(this);
        colorDialog.setVisible(true);
        Color selectedColor = colorDialog.getSelectedColor();
        if (selectedColor != null) {
            colorPanel.setBackground(selectedColor);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(MainFrame::new);
    }
}
