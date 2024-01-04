package GUI;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AdminWin extends JFrame {
    JButton employInfo;

    JButton queryInfo;

    JButton back;

    public AdminWin() {
        setTitle("高校学生就业管理系统-管理员界面");
        setBounds(500, 500, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        employInfo = new JButton("查询就业信息");
        queryInfo = new JButton("查询学生信息");
        back = new JButton("注销");

        employInfo.setBounds(50, 50, 200, 50);
        queryInfo.setBounds(50, 150, 200, 50);
        queryInfo.setBounds(50, 250, 200, 50);

        employInfo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AdminCal();
                dispose();
            }
        });


        queryInfo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AdminQuery();
                dispose();
            }
        });

        back.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new LoginWin();
                dispose();
            }
        });
        this.add(employInfo);
        this.add(queryInfo);
    }

}
