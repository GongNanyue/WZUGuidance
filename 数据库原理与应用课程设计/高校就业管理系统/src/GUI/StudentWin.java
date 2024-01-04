package GUI;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentWin extends JFrame {
    int ID;
    JButton fillIn;

    JButton back;

    public StudentWin(int ID) {
        this.ID = ID;
        setTitle("高校学生就业管理系统-学生界面");
        setBounds(300, 300, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        fillIn = new JButton("填入个人信息");
        back = new JButton("注销");

        fillIn.setBounds(50, 50, 200, 50);
        back.setBounds(50, 150, 100, 50);

        fillIn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StudentFillIn(ID);
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

        this.add(fillIn);
        this.add(back);
    }
}
