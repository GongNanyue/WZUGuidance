package GUI;

import DB.UserDB;
import Entity.User;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LoginWin extends JFrame {

    /**
     * 请选择身份
     */
    JLabel l1;
    String[] types = {"管理员", "学生"};
    JComboBox<String> selectBox;
    String selectType;

    /**
     * 用户名:
     */
    JLabel l2;
    JTextField username;


    /**
     * 密码
     */
    JLabel l3;
    JPasswordField password;

    JButton enter;
    JButton exist;


    public LoginWin() {
        setTitle("高校学生就业管理系统-登录界面");
        setBounds(500, 500, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        l1 = new JLabel("请选择身份");
        selectBox = new JComboBox<>(types);
        selectType = "管理员";
        l2 = new JLabel("用户名:");
        username = new JTextField();
        l3 = new JLabel("密码:");
        password = new JPasswordField();
        enter = new JButton("登录");
        exist = new JButton("退出");

        l1.setBounds(50, 50, 100, 50);
        selectBox.setBounds(200, 50, 200, 50);
        l2.setBounds(50, 150, 100, 50);
        username.setBounds(200, 150, 200, 50);
        l3.setBounds(50, 250, 100, 50);
        password.setBounds(200, 250, 200, 50);
        enter.setBounds(50, 350, 100, 50);
        exist.setBounds(200, 350, 100, 50);

        l1.setFont(new Font("等线", Font.BOLD, 18));
        selectBox.setFont(new Font("等线", Font.BOLD, 14));
        l2.setFont(new Font("等线", Font.BOLD, 18));
        l3.setFont(new Font("等线", Font.BOLD, 18));
        enter.setFont(new Font("等线", Font.BOLD, 18));
        exist.setFont(new Font("等线", Font.BOLD, 18));


        selectBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                selectType = (String) selectBox.getSelectedItem();
            }
        });


        enter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (selectType.equals("管理员")) {
                    User user = new UserDB().getUser(username.getText(), 0);
                    if (user != null && user.password.equals(password.getText())) {
                        new AdminWin();
                        dispose();
                    } else {
                        JOptionPane.showMessageDialog(LoginWin.this, "找不到账号或密码错误", "警告", JOptionPane.WARNING_MESSAGE);
                    }
                } else if (selectType.equals("学生")) {
                    User user = new UserDB().getUser(username.getText(), 1);
                    if ((user != null && user.password.equals(password.getText()))) {
                        new StudentWin(Integer.parseInt(username.getText()));
                        dispose();
                    } else {
                        JOptionPane.showMessageDialog(LoginWin.this, "找不到账号或密码错误", "警告", JOptionPane.WARNING_MESSAGE);
                    }
                } else {
                    JOptionPane.showMessageDialog(LoginWin.this, "请选择正确身份", "警告", JOptionPane.WARNING_MESSAGE);
                }
            }
        });

        exist.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        this.add(l1);
        this.add(selectBox);
        this.add(l2);
        this.add(username);
        this.add(l3);
        this.add(password);
        this.add(enter);
        this.add(exist);
    }
}
