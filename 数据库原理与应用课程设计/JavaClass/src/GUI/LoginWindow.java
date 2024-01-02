package GUI;

import DataBase.UserDB;
import Entity.User;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;

public class LoginWindow extends JFrame {
    JTextField name;
    JPasswordField password;
    JButton login;
    User user;

    public LoginWindow() {
        setLayout(null);
        setTitle("图书管理系统");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);

    }

    void init() {
        this.name = new JTextField(30);
        this.password = new JPasswordField(30);
        this.login = new JButton("登录");

        name.setBounds(this.getWidth() / 2, 50, 100, 30);
        password.setBounds(this.getWidth() / 2, 100, 100, 30);
        login.setBounds(this.getWidth() / 2, 150, 100, 30);


        login.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = name.getText();
                String password = LoginWindow.this.password.getText();
                try {
                    ResultSet rs = new UserDB().query(username, password);
                    if (rs.next()) {
                        user = new User(rs.getInt("reader_id"),
                                rs.getString("reader_name"),
                                rs.getString("reader_password"),
                                rs.getInt("reader_sex"),
                                rs.getInt("reader_type"),
                                rs.getInt("reader_capacity")
                        );
                        MainWindow win = new MainWindow(user);
                        LoginWindow.this.dispose();
                    } else {
                        JOptionPane.showMessageDialog(null, "登录失败");
                    }
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }
        });

        this.add(name);
        this.add(password);
        this.add(login);
    }
}
