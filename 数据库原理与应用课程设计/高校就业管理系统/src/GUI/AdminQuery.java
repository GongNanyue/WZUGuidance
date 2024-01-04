package GUI;

import DB.StudentDB;
import Entity.Student;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AdminQuery extends JFrame {
    JTextArea welcome;

    JLabel l1; // 学生学号:

    JTextField ID;

    JButton query;

    JButton back;

    JTextArea info;

    public AdminQuery() {
        setTitle("高校学生就业管理系统-管理员查询界面");
        setBounds(500, 500, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        welcome = new JTextArea();
        l1 = new JLabel("学生学号:");
        ID = new JTextField();
        query = new JButton("查询学生");
        back = new JButton("返回");
        info = new JTextArea();


        welcome.setBounds(50, 50, 400, 100);
        l1.setBounds(50, 200, 100, 50);
        ID.setBounds(200, 200, 100, 50);
        query.setBounds(50, 300, 100, 50);
        back.setBounds(200, 300, 100, 50);
        info.setBounds(50, 400, 800, 200);


        query.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Student s = new StudentDB().getStudent(Integer.parseInt(ID.getText()));
                if (s != null) {
                    String r1 = "学号\t姓名\t性别\t系别\t专业\t工作编号\t是否入职\n";
                    String r2 = s.ID + "\t" + s.name + "\t" + s.sex + "\t" + s.dept + "\t" + s.major + "\t" + s.jobID + "\t" + s.isWork + "\n";
                    info.append(r1 + r2);
                } else {
                    JOptionPane.showMessageDialog(AdminQuery.this, "没有找到该学生", "警告", JOptionPane.WARNING_MESSAGE);
                }
            }
        });

        back.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AdminWin();
                dispose();
            }
        });

        this.add(welcome);
        this.add(l1);
        this.add(ID);
        this.add(query);
        this.add(back);
        this.add(info);
    }


}
